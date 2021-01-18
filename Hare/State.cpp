#include "State.h"
#include <KeyboardEvent.h>
#include <EventHandler.h>
#include <iostream>

using namespace States;

State::~State()			//Leave the destructor definition empty since we don't need to add anything here
{						//at the moment.
}

void State::Init()		//Leave the method definition empty since we don't need to add anything here.
{
}

void State::Update()	//Leave the method definition empty since we don't need to add anything here.
{
}

void State::AddEvent(Events::Event* event)
{
	Events::EventHandler::AddEventToQueue(event);
}

void State::RemoveEvent(Events::EventID eventID)
{
	std::cout << "BEGIN REMOVING EVENT" << std::endl;
	std::cout << Events::EventHandler::GetQueue().size() << std::endl;

	for (Events::Event* event : Events::EventHandler::GetQueue())
	{
		std::cout << "dumb more dumb" << std::endl;
		std::cout << "dumb EVEN more dumb" << std::endl;

		std::cout << event->EventIDToChar() << std::endl;

		//TODO: I have no idea why this isn't working but it's not a priority right now i guess.
		if (event->eventID == Events::EventID::KeyboardEvent)
		{
			std::cout << "Dumb ULTRA" << std::endl;
			delete event;
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
