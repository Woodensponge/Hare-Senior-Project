#include "Timer.h"
#include "Application.h"

#include <SDL.h>
#include <iostream> //For debugging purposes

double Timer::deltaTime = 0;

Uint64 pastPC = 0;
Uint64 presentPC = 0;

double Timer::GetDeltaTime(bool isIndependentOnFramerate)
{
	if (isIndependentOnFramerate)
		return GetDeltaTime() * Application::fps;
	
	return GetDeltaTime();
}

void Timer::UpdateDeltaTime()
{
	presentPC = SDL_GetPerformanceCounter();	//Get the PC for this call.

	if (presentPC == 0)							//Make sure we don't divide by zero
	{
		deltaTime = 0;
		return;
	}

	//Calculate delta time.
	deltaTime = (double)((double)(presentPC - pastPC) / SDL_GetPerformanceFrequency());
	pastPC = presentPC;

	std::cout << deltaTime << std::endl;		//Print deltatime to the console.
}
