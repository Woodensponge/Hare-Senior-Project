#include "EntityManager.h"
#include "Debug.h"
#include "Player.h"
#include "Vector2.h"

#include <vector>

using namespace Hare;

std::map<int, std::string> entityTypeToStringMap =
{
	{(int)EntityType::None, "None"},
	{(int)EntityType::Player, "Player"}
};

Entity* EntityManager::GetClosestEntity(Entity* entity, std::vector<Hare::Entity*> entities)
{
	Entity* closestEntity = nullptr;
	float previousTargetDistance = 0;

	for (Entity* target : entities)
	{
		float targetDistance = entity->pos.CalculateDistance(entity->pos, target->pos);
		if (previousTargetDistance < targetDistance)
		{
			previousTargetDistance = targetDistance;
			closestEntity = target;
		}
	}

	return closestEntity;
}

Entity* EntityManager::GetEntityFromEnum(EntityType entityType)
{
	switch (entityType)
	{
	case EntityType::None:
		return new Entity();
	case EntityType::Player:
		return new Entities::Player(nullptr);
	}
	return nullptr;
}

EntityType EntityManager::GetEntityTypeFromString(std::string arg)
{
	for (auto& item : entityTypeToStringMap)
	{
		if (item.second == arg)
		{
			return static_cast<EntityType>(item.first);
		}
	}
	return EntityType::None;
}

Entity* EntityManager::GetEntityFromString(std::string arg)
{
	return GetEntityFromEnum(GetEntityTypeFromString(arg));
}
