/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELLOGENTRY_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELLOGENTRY_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "Color.h"

namespace viewmodel {

/**
 * Represents a log entry contained in a list. It contains a message and a color.
 */
class ViewModelLogEntry: public std::enable_shared_from_this<ViewModelLogEntry> {

private:

	framework::ObservablePrimitiveProperty<std::string> message;

	framework::ObservablePrimitiveProperty<viewmodel::Color> color;

public:

	ViewModelLogEntry();

	virtual const framework::ObservablePrimitiveProperty<std::string>& messageProperty() noexcept;

	virtual const framework::ObservablePrimitiveProperty<viewmodel::Color>& colorProperty() noexcept;

	virtual std::string getMessage() noexcept;

	virtual viewmodel::Color getColor() noexcept;

	virtual void setMessage(std::string message) noexcept;

	virtual void setColor(viewmodel::Color color) noexcept;

public:

	virtual ~ViewModelLogEntry() = default;

	static constexpr unsigned cFeatureKeyMessage = 1;
	static constexpr unsigned cFeatureKeyColor = 2;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELLOGENTRY_H

