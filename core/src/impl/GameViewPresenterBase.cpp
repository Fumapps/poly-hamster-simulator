#include "GameViewPresenterBase.h"

#include "Stage.h"
#include "GameLog.h"
#include "MpwSemaphore.h"
#include "CommandStack.h"
#include "GamePerformance.h"

#include "ViewModelLogEntry.h"

#include "CollectionHelpers.hpp"
#include <stdexcept>
#include <utility>

using namespace mpw;
using namespace collectionhelpers;
using namespace framework;

namespace viewmodel {

// TODO remove listeners on removement of relating objects

GameViewPresenterBase::GameViewPresenterBase(std::shared_ptr<mpw::MiniProgrammingWorld> miniProgrammingWorld)
        : inherited(Semaphore()), miniProgrammingWorld(std::move(miniProgrammingWorld)) {
}

void GameViewPresenterBase::bind() {
    const Size& size = getStageSizeFromConcreteStage();
    GameViewPresenter::getViewModel()->init(size);

    auto lock = getSemaphore().lock();

    bindTiles();
    bindGameLog();
    bindButtons();
    onBind();
}

void GameViewPresenterBase::bindTiles() {
    auto& tilesProperty = getTilesPropertyFromConcreteStage();

    tilesProperty.addOnAddedListener([this](auto& tile) { addTileNode(tile); });
    tilesProperty.addOnRemovedListener([this](auto& tile) { removeTileNode(tile); });
    tilesProperty.forEach([this](auto& tile) { addTileNode(tile); });
}

void GameViewPresenterBase::onBind() {
    // can be overridden by subclasses
}

void GameViewPresenterBase::bindGameLog() {
    auto miniProgrammingWorldLog = miniProgrammingWorld->getGameLog();
    miniProgrammingWorldLog->logEntriesProperty().addOnAddedListener([this](const LogEntry& entry) {
        auto lock = getSemaphore().lock();
        addLogEntry(entry);
    });
    miniProgrammingWorldLog->logEntriesProperty().addOnRemovedListener([this](const LogEntry& entry) {
        auto lock = getSemaphore().lock();
        removeLogEntry(entry);
    });
    miniProgrammingWorldLog->logEntriesProperty().forEach([this](const LogEntry& entry) {
        addLogEntry(entry);
    });
}

void GameViewPresenterBase::bindButtons() {
    auto viewModel = getViewModel();
    auto& modeProperty = miniProgrammingWorld->getPerformance()->modeProperty();
    auto gameCommandStack = miniProgrammingWorld->getPerformance()->getGameCommandStack();
    modeProperty.addListener([&](Mode, Mode) { updateButtonEnables(); });
    gameCommandStack->executedCommandsProperty().addOnAnyChangeListener(
            [&](const commands::Command&) { updateButtonEnables(); });
    gameCommandStack->undoneCommandsProperty().addOnAnyChangeListener(
            [&](const commands::Command&) { updateButtonEnables(); });
    updateButtonEnables();
}

void GameViewPresenterBase::updateButtonEnables() {
    auto viewModel = getViewModel();
    auto gameCommandStack = miniProgrammingWorld->getPerformance()->getGameCommandStack();

    Mode mode = miniProgrammingWorld->getPerformance()->getMode();
    bool anyExecutedCommand = !gameCommandStack->getExecutedCommands().empty();
    bool anyUndoneCommand = !gameCommandStack->getUndoneCommands().empty();

    viewModel->setPlayButtonEnabled(mode == Mode::PAUSED);
    viewModel->setPauseButtonEnabled(mode == Mode::RUNNING);
    viewModel->setUndoButtonEnabled(anyExecutedCommand && mode != Mode::RUNNING);
    viewModel->setRedoButtonEnabled(anyUndoneCommand && mode != Mode::RUNNING);
}

void GameViewPresenterBase::playClicked() {
    miniProgrammingWorld->getPerformance()->resumeGame();
}

void GameViewPresenterBase::pauseClicked() {
    miniProgrammingWorld->getPerformance()->pauseGame();
}

void GameViewPresenterBase::undoClicked() {
    miniProgrammingWorld->getPerformance()->getGameCommandStack()->undo();
}

void GameViewPresenterBase::redoClicked() {
    miniProgrammingWorld->getPerformance()->getGameCommandStack()->redo();
}

void GameViewPresenterBase::close() {
    miniProgrammingWorld->getPerformance()->abortOrStopGame();
}

void GameViewPresenterBase::addTileNode(const mpw::Tile& tile) {
    const Location& location = tile.getLocation();

    auto& contentsProperty = tile.contentsProperty();
    addedContentListenerIds[&tile] = contentsProperty.addOnAddedListener([this, &tile](const mpw::TileContent&) {
        auto lock = getSemaphore().lock();
        setTileNodeAt(tile.getLocation(), tile);
    });
    removedContentListenerIds[&tile] = contentsProperty.addOnRemovedListener([this, &tile](const mpw::TileContent&) {
        auto lock = getSemaphore().lock();
        setTileNodeAt(tile.getLocation(), tile);
    });
    setTileNodeAt(location, tile);
}

void GameViewPresenterBase::removeTileNode(const mpw::Tile& tile) {
    auto cell = getViewModel()->getCellAt(
            tile.getLocation().getRow(),
            tile.getLocation().getColumn());
    cell->clearLayers();
}

void GameViewPresenterBase::setTileNodeAt(const Location& location, const Tile& tile) {
    auto cell = getViewModel()->getCellAt(location.getRow(), location.getColumn());
    cell->clearLayers();

    onSetTileNodeAtForCell(*cell, tile);
}

int GameViewPresenterBase::getRotationForDirection(mpw::Direction direction) {
    switch (direction) {
        case Direction::EAST:
            return 0;
        case Direction::SOUTH:
            return 90;
        case Direction::WEST:
            return 180;
        case Direction::NORTH:
            return 270;
    }
    throw std::runtime_error("Invalid direction!");
}

void GameViewPresenterBase::addLogEntry(const LogEntry& entry) {
    auto viewModelEntry = std::make_shared<ViewModelLogEntry>();
    viewModelEntry->setMessage(entry.getMessage());
    viewModelEntry->setColor(getColorForLogEntry(entry));
    getViewModel()->addToLogEntries(viewModelEntry);
    gameLogMapping[&entry] = viewModelEntry.get();
}

void GameViewPresenterBase::removeLogEntry(const LogEntry& entry) {
    auto iterator = gameLogMapping.find(&entry);
    if (iterator != gameLogMapping.end()) {
        ViewModelLogEntry& viewModelEntry = *(*iterator).second;
        getViewModel()->removeFromLogEntries(viewModelEntry.shared_from_this());
        gameLogMapping.erase(iterator);
    }
}

void GameViewPresenterBase::speedChanged(double speedValue) {
    if (!(speedValue >= 0 && speedValue <= 10)) {
        throw std::runtime_error("Provided speed is not in range [0, 10]");
    }
    miniProgrammingWorld->getPerformance()->setSpeed(speedValue);
}

Color GameViewPresenterBase::getColorForLogEntry(const LogEntry& entry) const {
    return Color::BLACK;
}

}
