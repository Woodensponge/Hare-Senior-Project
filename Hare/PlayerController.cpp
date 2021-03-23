#include "Debug.h"
#include "PlayerController.h"
#include "Keyboard.h"

using namespace Events;
using namespace Events::EventTypes;

PlayerController::PlayerController(Hare::Entities::Player * player)
{
	this->eventID = EventID::PlayerController;
	this->isSingleOnly = true;

	this->player = player;
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(SDL_Event* event)
{
    //Don't do anything if the player is dead.
    if (player->entityFlags & Hare::ENTITYSTATE_DEAD)
    {
        return;
    }

    //Input for moving left
    if (Keyboard::IsKeyPressed(SDLK_a))
        currentMovement |= MOVE_LEFT;
    else
        currentMovement &= ~MOVE_LEFT;

    //Input for moving right
    if (Keyboard::IsKeyPressed(SDLK_d))
        currentMovement |= MOVE_RIGHT;
    else
        currentMovement &= ~MOVE_RIGHT;

    //Input for moving up
    if (Keyboard::IsKeyPressed(SDLK_w))
        currentMovement |= MOVE_UP;
    else
        currentMovement &= ~MOVE_UP;

    //Input for moving down
    if (Keyboard::IsKeyPressed(SDLK_s))
        currentMovement |= MOVE_DOWN;
    else
        currentMovement &= ~MOVE_DOWN;

    //Handling input
    if (currentMovement & MOVE_LEFT)
    {
        player->pos.x -= player->speed;
    }
    if (currentMovement & MOVE_RIGHT)
    {
        player->pos.x += player->speed;
    }
    if (currentMovement & MOVE_UP)
    {
        player->pos.y -= player->speed;
    }
    if (currentMovement & MOVE_DOWN)
    {
        player->pos.y += player->speed;
    }
}