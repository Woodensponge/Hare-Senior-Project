#include "Entity.h"
#include "Application.h"
#include "Debug.h"

#include <math.h>

using namespace Hare;

int Entity::nextEntityID = 0;

Entity::Entity()
	:hitbox(SDL_Rect())
{
	pos = Core::Vector2();

	this->AddFlags(ENTITYSTATE_ALIVE);

	entityID = nextEntityID;
	nextEntityID++;

	DEBUG_LOG_DEBUGONLY << "ENTITY CREATED WITH ID " << entityID;
}

Entity::~Entity()
{
	if (this->sprite != nullptr)
	{
		delete sprite;
	}

	DEBUG_LOG_DEBUGONLY 
		<< "ENTITY DESTROYED WITH ID " 
		<< entityID 
		<< " (" 
		<< entityTypeString
		<< ")";
}

/*
Kill the entity.
*/
void Entity::Die()
{
	if (entityFlags & ENTITYSTATE_DEAD)			//If already dead...
	{
		return;									//Don't need to die again.
	}

	DEBUG_LOG << "Die! " << entityTypeString;	//Obligatory Rain World debug message

	this->AddFlags(ENTITYSTATE_DEAD);
	this->RemoveFlags(ENTITYSTATE_ALIVE);
}

void Entity::Update()
{
	//Speed calculations and conditions

	if (isGrounded)
	{
		if (speed > 0)
			speed -= abs(speed / 8);
		else if (speed < 0)
			speed += abs(speed / 8);
	}

	if (!isGrounded)
	{
		if (speed > 0)
			speed -= abs(speed / 16);
		else if (speed < 0)
			speed += abs(speed / 16);
	}

	//Gravity calculations and conditions
	gravity += 1;

	if (gravity > 100)
		gravity = 100;
	else if (gravity < -100)
		gravity = -100;

	pos.x += speed;
	pos.y += gravity;

	UpdateHitbox();

	if (entityFlags & ENTITYSTATE_DEAD)			//If the entity is dead...
		return;									//Don't run the rest of the method.

	if (health < 0)								//If the entities health is 0...
		this->Die();							//Kill the entity.
}

void Entity::UpdateHitbox()
{
	hitbox.x = pos.ToRect().x;
	hitbox.y = pos.ToRect().y;
}

int Entity::AddFlags(int flags)
{
	this->entityFlags |= flags;
	return this->entityFlags;
}

int Entity::RemoveFlags(int flags)
{
	this->entityFlags &= ~flags;
	return this->entityFlags;
}
