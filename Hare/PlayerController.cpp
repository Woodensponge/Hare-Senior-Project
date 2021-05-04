#include "Debug.h"
#include "PlayerController.h"
#include "Keyboard.h"
#include "Level.h"

using namespace Events;
using namespace Events::EventTypes;

PlayerController::PlayerController(Hare::Entities::Player * player)
{
	this->eventID = EventID::PlayerController;
	this->player = player;
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(SDL_Event* event)
{
    //Input for restarting
    if (Keyboard::IsKeyPressed(SDLK_r))
    {
        player->level->Restart();
        return;
    }

    //Don't do anything below if the player is dead.
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

    //Input for dashing
    if (Keyboard::IsKeyPressed(SDLK_LSHIFT) && !player->hasDashed)
        currentMovement |= MOVE_DASH;
    else
        currentMovement &= ~MOVE_DASH;

    //Input for instant death
#ifdef _DEBUG
    if (Keyboard::IsKeyPressed(SDLK_p))
    {
        player->Die();
    }
#endif

    //Handling input
    if (currentMovement & MOVE_LEFT)
    {
        if (currentMovement & MOVE_DASH 
            && !player->hasDashed
            && !player->isGrounded)
        {
            player->hasDashed = true;
            player->speed = -30;
        }
        else
            player->speed -= player->acceleration;
    }

    if (currentMovement & MOVE_RIGHT)
    {
        if (currentMovement & MOVE_DASH 
            && !player->hasDashed
            && !player->isGrounded)
        {
            player->hasDashed = true;
            player->speed = 30;
        }
        else
            player->speed += player->acceleration;
    }

    if (Keyboard::IsKeyPressed(SDLK_w))
    {
        if (currentMovement & MOVE_DASH
            && !player->isGrounded)
        {
            player->hasDashed = true;
            player->gravity = -25;
        }
        else if (player->isGrounded == true)
        {
            player->gravity -= 15 + player->storedGravity;
        }
    }

    if (currentMovement & MOVE_DOWN 
        && player->isGrounded == false
        && player->isSlamming == false)
    {
        player->gravity = 30;
        player->isSlamming = true;
    }
}