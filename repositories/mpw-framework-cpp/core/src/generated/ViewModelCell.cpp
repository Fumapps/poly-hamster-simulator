/*
 * This file is generated. Do not change it manually.
 */

#include "ViewModelCell.h"

#include <stdexcept>

namespace viewmodel {

ViewModelCell::ViewModelCell() {

}

const framework::ObservableListProperty<viewmodel::ViewModelCellLayer>& ViewModelCell::layersProperty() noexcept {
	return this->layers;
}

const framework::ObservablePrimitiveProperty<mpw::Location>& ViewModelCell::locationProperty() noexcept {
	return this->location;
}

framework::ObjectListView<ViewModelCellLayer>& ViewModelCell::getLayers() noexcept {
	return this->layers;
}

mpw::Location ViewModelCell::getLocation() noexcept {
	return this->location.get();
}

void ViewModelCell::addToLayers(
		std::shared_ptr<viewmodel::ViewModelCellLayer> layer) noexcept {
	if (this->layersLookup.find(layer.get()) == this->layersLookup.end()) {
		this->layers.add(layer);
		this->layersLookup.insert(layer.get());
	}
}
void ViewModelCell::removeFromLayers(
		std::shared_ptr<viewmodel::ViewModelCellLayer> layer) noexcept {
	if (this->layersLookup.find(layer.get()) != this->layersLookup.end()) {
		this->layers.remove(layer);
		this->layersLookup.erase(layer.get());
	}
}

void ViewModelCell::clearLayers() noexcept {
	while (!this->layers.empty()) {
		removeFromLayers(this->layers.front());
	}
}

void ViewModelCell::setLocation(mpw::Location location) noexcept {
	auto previousLocation = this->getLocation();
	if (previousLocation != location) {
		this->location.set(location);
	}
}

}
