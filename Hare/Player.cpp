#include "Player.h"

using namespace Hare;
using namespace Hare::Entities;

Player::Player()
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	this->x = 0;
	this->y = 0;
}

Player::Player(int x, int y)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	this->x = x;
	this->y = y;
}

Player::Player(int flags)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	this->x = 0;
	this->y = 0;
	this->entityFlags = flags;
}

Player::Player(int x, int y, int flags)
{
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	this->x = x;
	this->y = y;
	this->entityFlags = flags;
}

Player::~Player()
{
}

void Player::Update()
{
}
