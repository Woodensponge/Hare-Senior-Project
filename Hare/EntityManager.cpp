#include "EntityManager.h"
#include "Debug.h"
#include "Player.h"

using namespace Hare;

std::map<int, std::string> entityTypeToStringMap =
{
	{(int)EntityType::None, "None"},
	{(int)EntityType::Player, "Player"}
};

Entity* EntityManager::GetEntityFromEnum(EntityType entityType)
{
	switch (entityType)
	{
	case EntityType::None:
		return new Entity();
	case EntityType::Player:
		return new Entities::Player();
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
