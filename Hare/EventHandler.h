#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include "Event.h"

#include <vector>

namespace Events 
{
	struct EventHandler
	{
		inline static std::vector<Event*> GetQueue() { return eventQueue; };

		static void UpdateEvents(SDL_Event* event);
		/*Adds an event to the queue. Returns address on success. Returns nullptr on failure.*/
		static Event* AddEventToQueue(Event* event);
		/*Destroys an event from the queue. Returns 0 on success. Returns 1 on failure.*/
		static int DestroyEvent(Event* event);
		static void DestroyQueue();

	private:
		static std::vector<Event*> eventQueue;
	};
}

#endif