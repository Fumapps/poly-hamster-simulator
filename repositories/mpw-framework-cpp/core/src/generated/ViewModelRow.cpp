/*
 * This file is generated. Do not change it manually.
 */

#include "ViewModelRow.h"

#include <stdexcept>

namespace viewmodel {

ViewModelRow::ViewModelRow() {

}

const framework::ObservableListProperty<viewmodel::ViewModelCell>& ViewModelRow::cellsProperty() noexcept {
	return this->cells;
}

framework::ObjectListView<ViewModelCell>& ViewModelRow::getCells() noexcept {
	return this->cells;
}

void ViewModelRow::addToCells(
		std::shared_ptr<viewmodel::ViewModelCell> cell) noexcept {
	if (this->cellsLookup.find(cell.get()) == this->cellsLookup.end()) {
		this->cells.add(cell);
		this->cellsLookup.insert(cell.get());
	}
}
void ViewModelRow::removeFromCells(
		std::shared_ptr<viewmodel::ViewModelCell> cell) noexcept {
	if (this->cellsLookup.find(cell.get()) != this->cellsLookup.end()) {
		this->cells.remove(cell);
		this->cellsLookup.erase(cell.get());
	}
}

void ViewModelRow::clearCells() noexcept {
	while (!this->cells.empty()) {
		removeFromCells(this->cells.front());
	}
}

}
