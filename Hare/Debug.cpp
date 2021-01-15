#include "Debug.h"

#include <iostream>
#include <string>

template<class T>
void Debug::Log(T arg)
{
	std::string string = arg;
	std::cout << string << std::endl;
	//TODO: Add file logging
}
