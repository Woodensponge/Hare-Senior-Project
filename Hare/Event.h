#ifndef EVENT_H_
#define EVENT_H_

#include "SDL.h"

namespace Events 
{
	enum class EventID
	{
		KeyboardEvent,
		None
	};

	struct Event
	{
		virtual ~Event();
		virtual void Update(SDL_Event* event);

		EventID eventID = EventID::None;
	};
}

#endif