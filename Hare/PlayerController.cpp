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
        player->speed -= player->acceleration;
    }
    if (currentMovement & MOVE_RIGHT)
    {
        player->speed += player->acceleration;
    }
    if (currentMovement & MOVE_UP && player->isGrounded == true)
    {
        player->gravity -= 15;
    }
    if (currentMovement & MOVE_DOWN 
        && player->isGrounded == false
        && player->isSlamming == false)
    {
        player->gravity = 20;
        player->isSlamming = true;
    }
}