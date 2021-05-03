#include "BasicEnemy.h"
#include "BasicEnemyAI.h"
#include "Debug.h"

using namespace Hare::Entities;

BasicEnemy::BasicEnemy()
	:BasicEnemy::BasicEnemy(0, 0 ,0, nullptr)
{
}

BasicEnemy::BasicEnemy(float x, float y)
	: BasicEnemy::BasicEnemy(x, y, 0, nullptr)
{
}

BasicEnemy::BasicEnemy(int flags)
	: BasicEnemy::BasicEnemy(0, 0, flags, nullptr)
{
}

Hare::Entities::BasicEnemy::BasicEnemy(Level* level)
	: BasicEnemy::BasicEnemy(0, 0, 0, level)
{
}

Hare::Entities::BasicEnemy::BasicEnemy(float x, float y, int flags, Level* level)
{
	this->level = level;
	this->entityType = EntityType::BasicEnemy;
	this->entityTypeString = "BasicEnemy";
	pos.x = x;
	pos.y = y;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	SDL_SetTextureColorMod
	(
		this->sprite->texture,
		255,
		0,
		0
	);
	this->sprite->layer = 5;
	this->entityFlags = flags;
	this->desiredSpeed = 5;
	this->acceleration = 1;

	this->ai = EntityAI::BasicEnemyAI(this);
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::Update()
{
	this->ai.Update();
	Entity::Update();
}
