/*
 * This file is generated. Do not change it manually.
 */

#include "GameViewPresenter.h"

#include <stdexcept>

#include "GameViewModel.h"

#include "GameViewModelImpl.h"

namespace viewmodel {

GameViewPresenter::GameViewPresenter(framework::Semaphore semaphore) {

	this->semaphore = semaphore;
	this->viewModel = std::make_shared<viewmodel::GameViewModelImpl>();
}

GameViewPresenter::~GameViewPresenter() = default;

std::shared_ptr<viewmodel::GameViewModel> GameViewPresenter::getViewModel() noexcept {
	return this->viewModel;
}

framework::Semaphore GameViewPresenter::getSemaphore() noexcept {
	return this->semaphore;
}

// TODO Source Operation void GameViewPresenter::bind() {}

}
