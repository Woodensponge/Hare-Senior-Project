#include "Event.h"
#include <iostream>

using namespace Events;

Event::~Event()							//Leave the destructor definition empty since we don't need to
{										//add anything here at the moment.
}

void Event::Update(SDL_Event* event)	//Leave the method definition empty since we don't need to
{										//add anything here.
}

void Event::ResetOnUpdate()				//Leave the method definition empty since we don't need to
{										//add anything here.
}

const char* Event::EventIDToChar()
{
	//TODO: I love enum class but holy shit I hate doing shit like this. Gotta find a better way of
	//doing this but it's not a priority at the moment.
	switch (eventID)
	{
	case EventID::None:
		return "None";
	case EventID::KeyboardEvent:
		return "KeyboardEvent";
	}

	return "EventID not specifed in EventIDToChar()";
}
