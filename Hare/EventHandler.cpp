#include "EventHandler.h"
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
	eventQueue.push_back(event);
}

void Events::EventHandler::DestroyEvent(Event* event)
{
	//TODO: Finding a good cpp style right this fucking instant
	for (int i = 0; i < eventQueue.size(); i++)
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
	for (Event* event : eventQueue)
		delete event;
}
