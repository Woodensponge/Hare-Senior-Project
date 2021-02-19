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
		PlayState(const char* levelJson);
		~PlayState();

		void Init();
		void Update();

	private:
		int windowWidth;
		int windowHeight;

		std::vector<Sprite*> sprites;
		Sprite* spriteCrosshair;
		SDL_Window* window;
		Level level;
	};
}

#endif