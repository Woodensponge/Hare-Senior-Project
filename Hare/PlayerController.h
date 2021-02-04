#ifndef PLAYERCONTROLLER_H_
#define PLAYERCONTROLLER_H_

#include "Event.h"

namespace Events
{
	namespace EventTypes
	{
		struct PlayerController : Event
		{
			PlayerController();
			~PlayerController();
			void Update(SDL_Event* event);
		};
	}
}
#endif