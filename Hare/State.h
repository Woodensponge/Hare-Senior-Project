#ifndef STATE_H_
#define STATE_H_

namespace States
{
	//Defines what type of state is being used.
	enum class StateID
	{
		PlayState,
		NotSpecified
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

		StateID stateID	= StateID::NotSpecified;
		StateID switchToState = StateID::NotSpecified;
		SubStateID subStateID = SubStateID::NoSubstate;
	};
}

#endif