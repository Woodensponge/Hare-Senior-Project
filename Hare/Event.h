#ifndef EVENT_H_
#define EVENT_H_

#include "SDL.h"

namespace Events 
{
	enum class EventID
	{
		None,
		KeyboardEvent,
		PlayerController
	};

	struct Event
	{
		virtual ~Event();
		virtual void Update(SDL_Event* event);
		virtual void ResetOnUpdate();
		
		const char* EventIDToChar();

		EventID eventID = EventID::None;
		bool isSingleOnly = false;				//Dictates whether or not multiple events of the same type
												//can exist at the same time.
		bool isPollable = false;				//Dictates whether or not the event should be polled next
												//update.
	};
}

#endif