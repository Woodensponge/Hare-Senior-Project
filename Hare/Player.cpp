#include "Player.h"
#include "Debug.h"
#include "Timer.h"

using namespace Hare;
using namespace Hare::Entities;

Player::Player()
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	pos.x = 0;
	pos.y = 0;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
}

Player::Player(float x, float y)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	pos.x = x;
	pos.y = y;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
}

Player::Player(int flags)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	pos.x = 0;
	pos.y = 0;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
	this->entityFlags = flags;
}

Player::Player(float x, float y, int flags)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	pos.x = x;
	pos.y = y;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
	this->entityFlags = flags;
}

Player::~Player()
{
}

void Player::Update()
{
	Entity::Update();
	this->pos.x += 3;
}
