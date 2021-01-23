#ifndef KEYBOARDEVENT_H_
#define KEYBOARDEVENT_H_

#include "Event.h"

namespace Events
{
	namespace EventTypes
	{
		enum class PlayerControls
		{
			MoveLeft,
			MoveRight,
			MoveUp,
			MoveDown,
			NotMoving
		};
		struct KeyboardEvent : Event
		{
			KeyboardEvent();
			~KeyboardEvent();

			void Update(SDL_Event* event);

			static PlayerControls currentAction[5];
		};
	}
}

#endif