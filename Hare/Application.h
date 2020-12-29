#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include <vector>
#include "Sprite.h"
#include <SDL.h>
#undef /*fucking*/ main

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
	Application
	(
		const char* title, 
		int windowWidth, 
		int windowHeight, 
		Uint32 flags, 
		int fps, 
		bool isCapped
	);
	~Application();

	int Init();
	void Update(double deltaTime);

	const char* windowTitle;
	Uint32 flags;

	bool isCapped = false;

	int windowWidth = 0;
	int windowHeight = 0;
	int fps = 60;

	GameState state = GameState::None;

	static SDL_Renderer* renderer;

private:

	Uint32 pastTicks = 0;				//Used to calculate delta time.

	SDL_Window* window;
	SDL_Event event;

	std::vector<Sprite*> sprites;
};

#endif
