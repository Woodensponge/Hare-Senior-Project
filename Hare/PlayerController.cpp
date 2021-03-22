#include "PlayerController.h"

using namespace Events;
using namespace Events::EventTypes;

PlayerController::PlayerController()
{
	this->eventID = EventID::PlayerController;
	this->isSingleOnly = true;
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(SDL_Event* event)
{

}