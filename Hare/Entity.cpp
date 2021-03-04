#include "Entity.h"
#include "Application.h"
#include "Debug.h"

using namespace Hare;

int Entity::nextEntityID = 0;

Entity::Entity()
	:hitbox(SDL_Rect())
{
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
	DEBUG_LOG << "Die! " << entityTypeString;	//Obligatory Rain World debug message

	this->AddFlags(ENTITYSTATE_DEAD);
	this->RemoveFlags(ENTITYSTATE_ALIVE);
}

/*
Updates the entity.
*/
void Entity::Update()
{
	if (entityFlags & ENTITYSTATE_DEAD)			//If the entity is dead...
		return;									//Don't run the rest of the method.

	if (health < 0)								//If the entities health is 0...
		this->Die();							//Kill the entity.
}

/*
Adds an entities flags.
Will return current flags after execution.
*/
int Entity::AddFlags(int flags)
{
	this->entityFlags &= flags;
	return this->entityFlags;
}

/*
Removes an entities flags.
Will return current flags after execution.
*/
int Entity::RemoveFlags(int flags)
{
	this->entityFlags &= ~flags;
	return this->entityFlags;
}
