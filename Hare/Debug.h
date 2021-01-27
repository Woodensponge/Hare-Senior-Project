#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <any>

struct Debug
{
	static void Log(const std::any arg);
};

#endif