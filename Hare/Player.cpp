#include "Player.h"
#include "Debug.h"
#include "TextureManager.h"
#include "Timer.h"
#include "EventHandler.h"
#include "PlayerController.h"

using namespace Hare;
using namespace Hare::Entities;
using namespace Events;

Player::Player() : Player::Player(0, 0, 0)
{
}

Player::Player(float x, float y) : Player::Player(x, y, 0)
{
}

Player::Player(int flags) : Player::Player(0, 0, flags)
{
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
	this->desiredSpeed = 5;
	this->acceleration = 1;

	pc = EventHandler::AddEventToQueue(new EventTypes::PlayerController(this));
	DEBUG_LOG << pc->EventIDToChar();
}

Player::~Player()
{
	DEBUG_LOG << EventHandler::DestroyEvent(pc);
}

void Player::Update()
{
	if (isGrounded == true)
	{
		hasDashed = false;
		isSlamming = false;
	}

	if (isSlamming)
	{
		speed = 0;
	}
	Entity::Update();
}
