#ifndef ENTITY_H_
#define ENTITY_H_

#include "Sprite.h"

#include <string>

namespace Hare
{
	enum EntityFlags
	{
		ENTITYSTATE_ALIVE = 1 << 0,
		ENTITYSTATE_DEAD = 1 << 1
	};

	enum class EntityType
	{
		None,
		Player
	};

	struct Entity
	{
		Entity();
		virtual ~Entity();

		inline EntityType GetEntityType()	{ return entityType; };
		
		/* Kills the entity. Does not destroy the entity. */
		virtual void Die();

		/* Updates the entity. */
		virtual void Update();

		/* Adds an entities flags. Will return current flags after execution. */
		int AddFlags(int flags);

		/* Removes an entities flags. Will return current flags after execution. */
		int RemoveFlags(int flags);

		int health = 100;

		unsigned int entityFlags = 0;
		int entityID = 0;
		EntityType entityType = EntityType::None;
		std::string entityTypeString = "None";

		SDL_Rect hitbox;
		Sprite* sprite = nullptr;

	private:
		static int nextEntityID;
	};
}

#endif