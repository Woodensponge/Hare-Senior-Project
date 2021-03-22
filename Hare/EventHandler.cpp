#include "EventHandler.h"
#include "Debug.h"
#include <iostream>
using namespace Events;

std::vector<Event*> EventHandler::eventQueue;

void EventHandler::UpdateEvents(SDL_Event* SDLEvent)
{
	for (Event* event : eventQueue)
	{
		if (event->isPollable)
			continue;
		event->Update(SDLEvent);
	}
}

void Events::EventHandler::UpdatePollableEvents(SDL_Event* SDLEvent)
{
	for (Event* event : eventQueue)
	{
		if (!event->isPollable)
			continue;
		event->Update(SDLEvent);
	}
}

Event* EventHandler::AddEventToQueue(Event* event)
{
	if (event->isSingleOnly == true)			//If only one event can exist at a time...
	{
		for (Event* _event : eventQueue)		//Check the event queue for events with the same ID
		{
			//If an event of the same ID exists in the event queue...
			if (event->eventID == _event->eventID)
			{
				delete event;					//Delete the event assigned.
				return nullptr;					//Stop the method.
			}
		}
	}
	eventQueue.push_back(event);
	return event;
}

int Events::EventHandler::DestroyEvent(Event* event)
{
	DEBUG_LOG << "ATTEMPTING TO DESTROY EVENT WITH EVENTID " << event->EventIDToChar();
	for (unsigned int i = 0; i < eventQueue.size(); i++)
	{
		if (eventQueue[i] == event)
		{
			DEBUG_LOG << "DESTROYING EVENT WITH EVENTID " << event->EventIDToChar();
			delete eventQueue[i];
			eventQueue.erase(eventQueue.begin() + i);
			return 0;
		}
	}
	return 1;
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
