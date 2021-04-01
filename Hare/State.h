#ifndef STATE_H_
#define STATE_H_

#include "Event.h"

#include <vector>

namespace States
{
	//Defines what type of state is being used.
	enum class StateID
	{
		NotSpecified,
		PlayState
	};

	enum class SubStateID
	{
		NoSubstate,
		Paused,
		Closing
	};

	struct State
	{
		virtual ~State();

		virtual void Init();
		virtual void Update();
		virtual void UpdateFixed();
		virtual void UpdatePhysics();
		
		void AddEvent(Events::Event* event);
		void RemoveEvents(Events::EventID eventID);
		void RemoveAllEvents();

		StateID stateID	= StateID::NotSpecified;
		StateID switchToState = StateID::NotSpecified;
		SubStateID subStateID = SubStateID::NoSubstate;

		bool hasPhysics = false;
	};
}

#endif