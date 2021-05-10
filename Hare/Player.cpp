#include "Player.h"
#include "Debug.h"
#include "EventHandler.h"
#include "Mouse.h"
#include "PlayerController.h"
#include "TextureManager.h"
#include "Timer.h"

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
	this->sprite = new Sprite("Assets/Entities/Player/Player-Simple.png", hitbox);
	this->sprite->layer = 5;
	this->entityFlags = ENTITYSTATE_ALIVE | flags;
	this->desiredSpeed = 5;
	this->acceleration = 1;

	pc = EventHandler::AddEventToQueue(new EventTypes::PlayerController(this));
}

Player::~Player()
{
	this->entityFlags = 0;
	DEBUG_LOG << "DESTROYED EVENT WITH CODE" << EventHandler::DestroyEvent(pc);
}

void Player::Update()
{
	//Aiming code.

	Core::Vector2 camPos = Core::Vector2
	(
		TextureManager::GetMainCamera()->size.x,
		TextureManager::GetMainCamera()->size.y
	);

	Core::Vector2 playerCenterPos = Core::Vector2
	(
		this->pos.x + (this->hitbox.w / 2),
		this->pos.y + (this->hitbox.h / 2)
	);
	Core::Vector2 aimPos = Core::Vector2(camPos.x + MOUSE_X(), camPos.y + MOUSE_Y());

	//Finding the angle here
	//std::cos(Core::Vector2::CalculateDistance());

	Line line = Line(playerCenterPos, aimPos);
	TextureManager::RenderLine(line);

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
