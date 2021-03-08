#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "Camera.h"
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
		void UpdateFixed();
		void Update();

	private:
		int windowWidth;
		int windowHeight;

		std::vector<Sprite*> sprites;
		Sprite* spriteCrosshair = nullptr;
		SDL_Window* window;
		Level level;
		Camera* camera;
	};
}

#endif