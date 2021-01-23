#include "State.h"
#include <KeyboardEvent.h>
#include <EventHandler.h>
#include <iostream>

using namespace States;
using namespace Events;

State::~State()			//Leave the destructor definition empty since we don't need to add anything here
{						//at the moment.
}

void State::Init()		//Leave the method definition empty since we don't need to add anything here.
{
}

void State::Update()	//Leave the method definition empty since we don't need to add anything here.
{
}

void State::AddEvent(Event* event)
{
	EventHandler::AddEventToQueue(event);
}

void State::RemoveEvent(Events::EventID eventID)
{
	std::cout << "BEGIN REMOVING EVENT" << std::endl;

	for (Event* event : EventHandler::GetQueue())
	{
		if (event->eventID == EventID::KeyboardEvent)
		{
			EventHandler::DestroyEvent(event);
			return;
		}

		else if (event->eventID != eventID)
		{
			continue;
		}
	}
}

void States::State::RemoveAllEvents()
{
	/*
	for (Events::Event* event : this->events)
	{
		Events::EventHandler::
	}
	*/
}
