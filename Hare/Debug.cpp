#include "Debug.h"

#include <iostream>
#include <string>

void Debug::Log(const std::any arg)
{
	std::string argString;

	std::any_cast(arg);
	
	if (isnan(arg))
	{
		argString.append();
	}
}
