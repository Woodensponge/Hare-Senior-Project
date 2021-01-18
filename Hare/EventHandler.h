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
		static void AddEventToQueue(Event* event);
		static void DestroyQueue();

	private:
		static std::vector<Event*> eventQueue;
	};
}

#endif