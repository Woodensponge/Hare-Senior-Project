#include "EventHandler.h"

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

void EventHandler::DestroyQueue()
{
	for (Event* event : eventQueue)
		delete event;
}
