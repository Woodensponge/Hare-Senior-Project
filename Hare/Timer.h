#ifndef TIMER_H_
#define TIMER_H_

#define FPS_TO_MILL (1000 / Timer::fps)

struct Timer
{
	static inline double GetDeltaTime() { return deltaTime; };
	static double GetDeltaTime(bool isDependentOnFramerate);
	static void UpdateDeltaTime();

	static int fps;

private:
	static double deltaTime;
};

#endif