#ifndef EVENT_H_
#define EVENT_H_

#include "SDL.h"

namespace Events 
{
	enum class EventID
	{
		None,
		KeyboardEvent
	};

	struct Event
	{
		virtual ~Event();
		virtual void Update(SDL_Event* event);
		virtual void ResetOnUpdate();

		const char* EventIDToChar();

		EventID eventID = EventID::None;
		bool resetsOnUpdate = false;
	};
}

#endif