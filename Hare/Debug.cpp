#include "Debug.h"

#include <iostream>

template<class T>
void Debug::Log(T arg)
{
	std::cout << arg << std::endl;
	//TODO: Add file logging
}
