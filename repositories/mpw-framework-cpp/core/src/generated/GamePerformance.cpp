/*
 * This file is generated. Do not change it manually.
 */

#include "GamePerformance.h"

#include <stdexcept>

#include "CommandStack.h"

#include "CommandStackImpl.h"

namespace mpw {

GamePerformance::GamePerformance(framework::Semaphore semaphore) {

	this->semaphore = semaphore;
	this->gameCommandStack = std::make_shared<commands::CommandStackImpl>();
	this->mode.set(mpw::Mode::INITIALIZING);
	this->speed.set(4.0);
	this->delayEnabled.set(true);
}

GamePerformance::~GamePerformance() = default;

const framework::ObservablePrimitiveProperty<mpw::Mode>& GamePerformance::modeProperty() noexcept {
	return this->mode;
}

const framework::ObservablePrimitiveProperty<double>& GamePerformance::speedProperty() noexcept {
	return this->speed;
}

const framework::ObservablePrimitiveProperty<bool>& GamePerformance::delayEnabledProperty() noexcept {
	return this->delayEnabled;
}

framework::Semaphore GamePerformance::getSemaphore() noexcept {
	return this->semaphore;
}

mpw::Mode GamePerformance::getMode() noexcept {
	return this->mode.get();
}

double GamePerformance::getSpeed() noexcept {
	return this->speed.get();
}

bool GamePerformance::getDelayEnabled() noexcept {
	return this->delayEnabled.get();
}

std::shared_ptr<commands::CommandStack> GamePerformance::getGameCommandStack() noexcept {
	return this->gameCommandStack;
}

void GamePerformance::setMode(mpw::Mode mode) noexcept {
	this->mode.set(mode);
}

void GamePerformance::setSpeed(double speed) noexcept {
	this->speed.set(speed);
}

void GamePerformance::setDelayEnabled(bool delayEnabled) noexcept {
	this->delayEnabled.set(delayEnabled);
}

// TODO Source Operation void GamePerformance::startGame() {}
// TODO Source Operation void GamePerformance::startGamePaused() {}
// TODO Source Operation void GamePerformance::pauseGame() {}
// TODO Source Operation void GamePerformance::resumeGame() {}
// TODO Source Operation void GamePerformance::stopGame() {}
// TODO Source Operation void GamePerformance::hardReset() {}
// TODO Source Operation void GamePerformance::abortOrStopGame() {}
// TODO Source Operation void GamePerformance::preExecuteGameCommand() {}
// TODO Source Operation void GamePerformance::preExecuteEditorCommand() {}
// TODO Source Operation void GamePerformance::delayControlFlow() {}

}