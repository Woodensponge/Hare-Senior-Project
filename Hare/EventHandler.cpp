#include "EventHandler.h"
#include "Debug.h"
#include <iostream>
using namespace Events;

std::vector<Event*> EventHandler::eventQueue;

void EventHandler::UpdateEvents(SDL_Event* SDLEvent)
{
	for (Event* event : eventQueue)
		event->Update(SDLEvent);
}

void EventHandler::AddEventToQueue(Event* event)
{
	if (event->isSingleOnly == true)			//If only one event can exist at a time...
	{
		for (Event* _event : eventQueue)		//Check the event queue for events with the same ID
		{
			//If an event of the same ID exists in the event queue...
			if (event->eventID == _event->eventID)
			{
				delete event;					//Delete the event assigned.
				return;							//Stop the method.
			}
		}
	}
	eventQueue.push_back(event);
}

void Events::EventHandler::DestroyEvent(Event* event)
{
	for (unsigned int i = 0; i < eventQueue.size(); i++)
	{
		if (eventQueue[i] == event)
		{
			std::cout << "DESTROYING EVENT WITH EVENTID " << event->EventIDToChar() << std::endl;
			delete eventQueue[i];
			eventQueue.erase(eventQueue.begin() + i);
		}
	}
}

void EventHandler::DestroyQueue()
{
	DEBUG_LOG << "Destroying eventQueue with size " << eventQueue.size();

	if (eventQueue.empty())
		return;

	for (Event* event : eventQueue)
		delete event;

	eventQueue.clear();
}
