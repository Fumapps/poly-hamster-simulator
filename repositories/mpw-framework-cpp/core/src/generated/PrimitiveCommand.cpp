/*
 * This file is generated. Do not change it manually.
 */

#include "PrimitiveCommand.h"

#include <stdexcept>

#include "Entity.h"

namespace commands {

PrimitiveCommand::PrimitiveCommand() {

}

PrimitiveCommand::~PrimitiveCommand() = default;

std::shared_ptr<basetypes::Entity> PrimitiveCommand::getEntity() noexcept {
	return this->entity;
}

std::string PrimitiveCommand::getPropertyName() noexcept {
	return this->propertyName;
}

int PrimitiveCommand::getFeatureKey() noexcept {
	return this->featureKey;
}

void PrimitiveCommand::setEntity(
		std::shared_ptr<basetypes::Entity> entity) noexcept {
	auto previousEntity = this->getEntity();
	if (previousEntity != entity) {
		this->entity = entity;
	}
}

void PrimitiveCommand::setPropertyName(std::string propertyName) noexcept {
	this->propertyName = propertyName;
}

void PrimitiveCommand::setFeatureKey(int featureKey) noexcept {
	this->featureKey = featureKey;
}

}