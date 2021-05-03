#include "Player.h"
#include "Debug.h"
#include "TextureManager.h"
#include "Timer.h"
#include "EventHandler.h"
#include "PlayerController.h"

using namespace Hare;
using namespace Hare::Entities;
using namespace Events;

Player::Player(Level* level) : Player::Player(0, 0, 0, level)
{
}

Player::Player(float x, float y, Level* level) : Player::Player(x, y, 0, level)
{
}

Player::Player(int flags, Level* level) : Player::Player(0, 0, flags, level)
{
}

Player::Player(float x, float y, int flags, Level* level)
{
	this->level = level;
	this->entityType = EntityType::Player;
	this->entityTypeString = "Player";
	pos.x = x;
	pos.y = y;
	hitbox.w = 20;
	hitbox.h = 20;
	this->sprite = new Sprite("Assets/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
	this->entityFlags = ENTITYSTATE_ALIVE | flags;
	this->desiredSpeed = 5;
	this->acceleration = 1;

	pc = EventHandler::AddEventToQueue(new EventTypes::PlayerController(this));
}

Player::~Player()
{
	DEBUG_LOG << "DESTROYED EVENT WITH CODE" << EventHandler::DestroyEvent(pc);
}

void Player::Update()
{
	if (isGrounded == true)
	{
		storedGravity = 0;

		hasDashed = false;
		isSlamming = false;
	}

	if (isSlamming)
	{
		storedGravity++;
		speed = 0;
	}
	Entity::Update();
}
