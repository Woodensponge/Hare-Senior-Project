#include "Timer.h"
#include "Application.h"

#include <SDL.h>
#include <iostream> //For debugging purposes

double Timer::deltaTime = 0;

Uint32 pastTicks = 0;
Uint32 presentTicks = 0;

double Timer::GetDeltaTime(bool isIndependentOnFramerate)
{
	if (isIndependentOnFramerate)
		return GetDeltaTime() * Application::fps;
	
	return GetDeltaTime();
}

void Timer::UpdateDeltaTime()
{
	presentTicks = SDL_GetTicks();	//Get the PC for this call.

	if (presentTicks == 0)							//Make sure we don't divide by zero
	{
		deltaTime = 0;
		return;
	}

	//Calculate delta time.
	deltaTime = (double)((presentTicks - pastTicks) / 1000.0f);
	pastTicks = presentTicks;

	//std::cout << deltaTime << std::endl;		//Print deltatime to the console.
}
