#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include <SDL.h>
#undef main

enum class GameState
{
	Running,
	Paused,
	Minimized,
	Closing,
	None
};

struct Application
{
	Application(const char* title, int windowWidth, int windowHeight, Uint32 flags);
	Application(const char* title, int windowWidth, int windowHeight, Uint32 flags, int fps);
	~Application();

	inline double GetDeltaTime();
	int Init();
	void Update();

	const char* windowTitle;
	Uint32 flags;

	int windowWidth = 0;
	int windowHeight = 0;
	int fps = 60;

	GameState state = GameState::None;

private:

	Uint32 pastTicks = 0;				//Used to calculate delta time.

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
};

#endif
