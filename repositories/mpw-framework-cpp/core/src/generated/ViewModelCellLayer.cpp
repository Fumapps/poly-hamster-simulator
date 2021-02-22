/*
 * This file is generated. Do not change it manually.
 */

#include "ViewModelCellLayer.h"

#include <stdexcept>

namespace viewmodel {

ViewModelCellLayer::ViewModelCellLayer() {

}

const framework::ObservablePrimitiveProperty<std::string>& ViewModelCellLayer::imageNameProperty() noexcept {
	return this->imageName;
}

const framework::ObservablePrimitiveProperty<int>& ViewModelCellLayer::rotationProperty() noexcept {
	return this->rotation;
}

const framework::ObservablePrimitiveProperty<bool>& ViewModelCellLayer::visibleProperty() noexcept {
	return this->visible;
}

std::string ViewModelCellLayer::getImageName() noexcept {
	return this->imageName.get();
}

int ViewModelCellLayer::getRotation() noexcept {
	return this->rotation.get();
}

bool ViewModelCellLayer::getVisible() noexcept {
	return this->visible.get();
}

void ViewModelCellLayer::setImageName(std::string imageName) noexcept {
	this->imageName.set(imageName);
}

void ViewModelCellLayer::setRotation(int rotation) noexcept {
	this->rotation.set(rotation);
}

void ViewModelCellLayer::setVisible(bool visible) noexcept {
	this->visible.set(visible);
}

}
