#include "AddEntityCommandImpl.h"

#include "Entity.h"

namespace commands {

AddEntityCommandImpl::AddEntityCommandImpl() {
}

void AddEntityCommandImpl::execute() {
    auto entity = getEntity();
    EntityReference reference = getEntityToAdd().get();
    entity->addToCollection(getPropertyName(), reference);
}

void AddEntityCommandImpl::undo() {
    auto entity = getEntity();
    EntityReference reference = getEntityToAdd().get();
    entity->removeFromCollection(getPropertyName(), reference);
}

void AddEntityCommandImpl::redo() {
	execute();
}

}

