#ifndef PLAYERCONTROLLER_H_
#define PLAYERCONTROLLER_H_

#include "Event.h"
#include "Player.h"

namespace Events
{
	namespace EventTypes
	{
		struct PlayerController : Event
		{
			enum Movement
			{
				MOVE_LEFT = 1 << 0,
				MOVE_RIGHT = 1 << 1,
				MOVE_UP = 1 << 3,
				MOVE_DOWN = 1 << 4,
				DASH = 1 << 5,
			};

			PlayerController(Hare::Entities::Player* player);
			~PlayerController();
			void Update(SDL_Event* event);

			Hare::Entities::Player* player;

			int currentMovement = 0;
		};
	}
}
#endif