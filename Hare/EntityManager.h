#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include "Entity.h"
#include "Level.h"

#include <map>

namespace Hare
{
	struct EntityManager
	{
		static Hare::Entity* GetClosestEntity(Hare::Entity* entity, std::vector<Hare::Entity*> entities);
		static Hare::Entity* GetEntityFromEnum(Hare::EntityType entityType);
		static Hare::EntityType GetEntityTypeFromString(std::string arg);
		static Hare::Entity* GetEntityFromString(std::string arg);
	};
}

#endif