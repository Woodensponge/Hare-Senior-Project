#include "Player.h"
#include "Debug.h"
#include "Timer.h"

using namespace Hare;
using namespace Hare::Entities;

Player::Player()
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	hitbox.x = 0;
	hitbox.y = 0;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
}

Player::Player(int x, int y)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	hitbox.x = x;
	hitbox.y = y;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
}

Player::Player(int flags)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	hitbox.x = 0;
	hitbox.y = 0;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
	this->entityFlags = flags;
}

Player::Player(int x, int y, int flags)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	hitbox.x = x;
	hitbox.y = y;
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
	this->hitbox.x += 1;
}
