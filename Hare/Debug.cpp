#include "Application.h"
#include "Debug.h"

#include <SDL.h>
#include <iostream>
#include <string>

using namespace Debug;

//A constructor with a definition as empty as my stomach.
Log::Log()
{
}

Log::Log(LogEnum mode)
{
	switch (mode)
	{
	case LogEnum::NoRestrictions:		//Log the data with no restrictions
		break;
	case LogEnum::DebugOnly:			//If program is not a debug build, dont output anything.
#ifndef _DEBUG
		canLog = false;
#endif
		break;
	case LogEnum::ReleaseOnly:			//If program is not a release build, dont output anything.
#ifndef NDEBUG
		canLog = false;
#endif
		break;
	}
}

Log::~Log()
{
	if (canLog)
	{
		std::cout << oss.str() << std::endl;
	}
}

void Error::ShowSDLMessageBox(const char* errorMessage)
{
	std::ostringstream oss;
	oss << errorMessage << "\nSDL Error: " << SDL_GetError();

	DEBUG_LOG << oss.str().c_str();
	SDL_ShowSimpleMessageBox(0, "Error", oss.str().c_str(), Application::GetWindow());
}
