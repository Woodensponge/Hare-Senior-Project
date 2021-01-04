#ifndef DEBUG_H_
#define DEBUG_H_

#include <any>

struct Debug
{
	template<class T>
	static void Log(T arg);
};

#endif