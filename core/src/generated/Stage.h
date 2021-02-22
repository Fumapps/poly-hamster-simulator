/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_STAGE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_STAGE_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "ObjectListView.hpp"
#include "Entity.h"
#include "Size.h"
#include "Tile.h"
#include "TileContent.h"

namespace mpw {

/**
 * A concrete stage can be designed by derived from the Stage class.
 * 
 * A stage consists of a two-dimensional mesh of Tile objects, which
 * has the dimensions defined in the stageSize property.
 * The size is defined by a given number of columns and rows.
 * 
 * Besides the collection of Tile objects, it also acts as the container
 * of the TileContent objects, which can be referenced to the tiles.
 */
class Stage: public virtual basetypes::Entity {

private:

	framework::ObservableObjectContainmentListProperty<Tile> tiles;
	/// \brief internal lookup for tiles
	std::unordered_set<mpw::Tile*> tilesLookup;

	framework::ObservableObjectContainmentListProperty<TileContent> tileContents;
	/// \brief internal lookup for tileContents
	std::unordered_set<mpw::TileContent*> tileContentsLookup;

	framework::ObservablePrimitiveProperty<mpw::Size> stageSize;

public:

	Stage();

	/// \brief returns a shared_ptr of type Stage which shares ownership of *this
	std::shared_ptr<Stage> shared_from_this() {
		return std::dynamic_pointer_cast < Stage
				> (basetypes::Entity::shared_from_this());
	}

	virtual const framework::ObservableListProperty<mpw::Tile>& tilesProperty() noexcept;

	virtual const framework::ObservableListProperty<mpw::TileContent>& tileContentsProperty() noexcept;

	virtual const framework::ObservablePrimitiveProperty<mpw::Size>& stageSizeProperty() noexcept;

	virtual framework::ObjectListView<Tile>& getTiles() noexcept;

	virtual framework::ObjectListView<TileContent>& getTileContents() noexcept;

	virtual mpw::Size getStageSize() noexcept;

	virtual void addToTiles(std::shared_ptr<mpw::Tile> tile) noexcept;
	virtual void removeFromTiles(std::shared_ptr<mpw::Tile> tile) noexcept;
	virtual void clearTiles() noexcept;

	virtual void addToTileContents(
			std::shared_ptr<mpw::TileContent> tileContent) noexcept;
	virtual void removeFromTileContents(
			std::shared_ptr<mpw::TileContent> tileContent) noexcept;
	virtual void clearTileContents() noexcept;

	virtual void setStageSize(mpw::Size stageSize) noexcept;

public:

	virtual ~Stage() = 0;

	static constexpr unsigned cFeatureKeyTiles = 1;
	static constexpr unsigned cFeatureKeyTileContents = 2;
	static constexpr unsigned cFeatureKeyStageSize = 3;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_STAGE_H

