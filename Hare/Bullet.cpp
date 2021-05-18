#include "Bullet.h"

using namespace Hare::Entities;

Bullet::Bullet(Level* level)
	: Bullet::Bullet(0, 0, 0, level)
{
}

Bullet::Bullet(float x, float y, Level* level)
	: Bullet::Bullet(x, y, 0, level)
{
}

Bullet::Bullet(int flags, Level* level)
	: Bullet::Bullet(0, 0, flags, level)
{
}

Bullet::Bullet(float x, float y, int flags, Level* level)
{
	this->level = level;
	this->entityType = EntityType::Bullet;
	this->entityTypeString = "Bullet";
	pos.x = x;
	pos.y = y;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Entities/Player/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
	this->entityFlags = ENTITYSTATE_ALIVE | flags;
	this->desiredSpeed = 5;
	this->acceleration = 1;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{

}
