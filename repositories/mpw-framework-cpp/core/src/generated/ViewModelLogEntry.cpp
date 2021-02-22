/*
 * This file is generated. Do not change it manually.
 */

#include "ViewModelLogEntry.h"

#include <stdexcept>

namespace viewmodel {

ViewModelLogEntry::ViewModelLogEntry() {

}

const framework::ObservablePrimitiveProperty<std::string>& ViewModelLogEntry::messageProperty() noexcept {
	return this->message;
}

const framework::ObservablePrimitiveProperty<viewmodel::Color>& ViewModelLogEntry::colorProperty() noexcept {
	return this->color;
}

std::string ViewModelLogEntry::getMessage() noexcept {
	return this->message.get();
}

viewmodel::Color ViewModelLogEntry::getColor() noexcept {
	return this->color.get();
}

void ViewModelLogEntry::setMessage(std::string message) noexcept {
	this->message.set(message);
}

void ViewModelLogEntry::setColor(viewmodel::Color color) noexcept {
	this->color.set(color);
}

}
