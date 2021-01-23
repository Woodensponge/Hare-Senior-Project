#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "State.h"
#include "Sprite.h"
#include "Level.h"

#include <SDL.h>
#include <vector>

namespace States
{
	struct PlayState : State
	{
		PlayState(SDL_Window* window);
		~PlayState();

		void Init();
		void Update();

	private:
		int windowWidth;
		int windowHeight;

		std::vector<Sprite*> sprites;
		SDL_Window* window;
		Level level;
	};
}

#endif