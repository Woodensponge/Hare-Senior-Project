#include "Timer.h"

#include <SDL.h>
#include <iostream> //For debugging purposes

double Timer::deltaTime = 0;
double Timer::unboundDt = 0;
int Timer::fps = 60;

Uint64 pastTicks = 0;
Uint64 presentTicks = 0;

double Timer::GetDeltaTime(bool isIndependentOnFramerate)
{
	if (isIndependentOnFramerate)
		return GetDeltaTime() * fps;
	
	return GetDeltaTime();
}

void Timer::UpdateDeltaTime()
{
	presentTicks = SDL_GetPerformanceCounter();					//Get the ticks for this call.

	if (presentTicks == 0)							//Make sure we don't divide by zero
	{
		deltaTime = 0;
		return;
	}

	//Calculate delta time.
	deltaTime = (double)((presentTicks - pastTicks) * 1000 / (double)SDL_GetPerformanceFrequency()) / 100;
	unboundDt = deltaTime * fps;
	
	pastTicks = presentTicks;

	//std::cout << deltaTime << std::endl;			//Print deltatime to the console.
}