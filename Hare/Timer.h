#ifndef TIMER_H_
#define TIMER_H_

struct Timer
{
	static inline double GetDeltaTime() { return deltaTime; };
	static double GetDeltaTime(bool isDependentOnFramerate);
	static void UpdateDeltaTime();

	static int fps;
	static double deltaTime;
	static double unboundDt;
};

#endif