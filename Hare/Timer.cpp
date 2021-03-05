#include "Timer.h"

#include <SDL.h>
#include <iostream> //For debugging purposes

double Timer::deltaTime = 0;
double Timer::fixedDt = 0;
int Timer::fps = 60;

Uint64 pastTicks = 0;
Uint64 presentTicks = 0;

Uint64 fixedPastTicks = 0;
Uint64 fixedPresentTicks = 0;

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
	deltaTime = (double)((presentTicks - pastTicks) / (double)SDL_GetPerformanceFrequency());
	
	pastTicks = presentTicks;

	//std::cout << deltaTime << std::endl;			//Print deltatime to the console.
}

void Timer::UpdateFixedDeltaTime()
{
	fixedPresentTicks = SDL_GetPerformanceCounter();					//Get the ticks for this call.

	if (fixedPresentTicks == 0)							//Make sure we don't divide by zero
	{
		fixedDt = 0;
		return;
	}

	//Calculate delta time.
	fixedDt = (double)((fixedPresentTicks - fixedPastTicks) / (double)SDL_GetPerformanceFrequency());

	fixedPastTicks = fixedPresentTicks;

	//std::cout << deltaTime << std::endl;			//Print deltatime to the console.
}
