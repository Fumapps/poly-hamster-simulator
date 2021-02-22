/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELROW_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELROW_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "ObjectListView.hpp"
#include "ViewModelCell.h"

namespace viewmodel {

/**
 * Represents a row in the view-model, which contains one ViewModelCell for each column.
 */
class ViewModelRow: public std::enable_shared_from_this<ViewModelRow> {

private:

	framework::ObservableObjectContainmentListProperty<ViewModelCell> cells;
	/// \brief internal lookup for cells
	std::unordered_set<viewmodel::ViewModelCell*> cellsLookup;

public:

	ViewModelRow();

	virtual const framework::ObservableListProperty<viewmodel::ViewModelCell>& cellsProperty() noexcept;

	virtual framework::ObjectListView<ViewModelCell>& getCells() noexcept;

	virtual void addToCells(
			std::shared_ptr<viewmodel::ViewModelCell> cell) noexcept;
	virtual void removeFromCells(
			std::shared_ptr<viewmodel::ViewModelCell> cell) noexcept;
	virtual void clearCells() noexcept;

public:

	virtual ~ViewModelRow() = default;

	static constexpr unsigned cFeatureKeyCells = 1;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELROW_H

