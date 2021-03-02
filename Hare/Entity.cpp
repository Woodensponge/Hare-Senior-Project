#include "Entity.h"
#include "Debug.h"

using namespace Hare;

Entity::Entity()
{
	this->AddFlags(ENTITYSTATE_ALIVE);
}

Entity::~Entity()
{
	if (this->sprite != nullptr)
	{
		delete sprite;
	}
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
