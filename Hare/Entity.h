#ifndef ENTITY_H_
#define ENTITY_H_

#include "Sprite.h"
#include "Vector2.h"

#include <string>

struct Level;

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
		Player,
		BasicEnemy
	};

	struct Entity
	{
		Entity();
		Entity(Level* level);
		virtual ~Entity();

		inline EntityType GetEntityType()	{ return entityType; };
		
		/* Kills the entity. Does not destroy the entity. */
		virtual void Die();

		/* Updates the entity. */
		virtual void Update();

		/* Updates the entitys hitbox. */
		virtual void UpdateHitbox();

		/* Adds an entities flags. Will return current flags after execution. */
		inline int AddFlags(int flags);

		/* Removes an entities flags. Will return current flags after execution. */
		inline int RemoveFlags(int flags);

		int health = 100;
		float desiredSpeed = 1;
		float speed = 0;
		float gravity = 0;
		float acceleration = 1;

		bool isGrounded = false;

		unsigned int entityFlags = 0;
		int entityID = 0;
		EntityType entityType = EntityType::None;
		std::string entityTypeString = "None";

		SDL_Rect hitbox;
		Core::Vector2 pos;
		Sprite* sprite = nullptr;

		Level* level;

	private:
		static int nextEntityID;
	};
}

#endif