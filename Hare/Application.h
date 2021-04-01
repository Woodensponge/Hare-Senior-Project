#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Sprite.h"
#include "State.h"

#include <iostream>
#include <vector>
#include <SDL.h>

#undef /*fucking*/ main

enum class GameState
{
	Running,
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

	inline static SDL_Window* GetWindow() { return window; };
	int Init();
	void Render();
	void Update();				//Updates based on framerate
	void UpdateFixed();			//Updates based on ticks
	void UpdatePhysics();

	const char* windowTitle;
	Uint32 flags;

	bool isCapped = false;

	int windowWidth = 0;
	int windowHeight = 0;

	static GameState gameState;

	static SDL_Renderer* renderer;
	static SDL_Event event;

	static Uint64 ticks;
private:
	static SDL_Window* window;
	std::vector<Sprite*> sprites;

	States::State* state;
};

#endif
