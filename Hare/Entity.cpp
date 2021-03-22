#include "Entity.h"
#include "Application.h"
#include "Debug.h"

using namespace Hare;

int Entity::nextEntityID = 0;

Entity::Entity()
	:hitbox(SDL_Rect())
{
	pos = Vector2();

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

void Entity::Update()
{
	hitbox.x = pos.ToRect().x;
	hitbox.y = pos.ToRect().y;

	if (entityFlags & ENTITYSTATE_DEAD)			//If the entity is dead...
		return;									//Don't run the rest of the method.

	if (health < 0)								//If the entities health is 0...
		this->Die();							//Kill the entity.
}

int Entity::AddFlags(int flags)
{
	this->entityFlags &= flags;
	return this->entityFlags;
}

int Entity::RemoveFlags(int flags)
{
	this->entityFlags &= ~flags;
	return this->entityFlags;
}
