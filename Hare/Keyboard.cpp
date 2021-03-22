#include "Keyboard.h"
#include "Debug.h"

std::map<int, bool> Keyboard::keys;

void Keyboard::UpdateKeyboard(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_KEYDOWN:
		keys[event->key.keysym.sym] = true;
		break;
	case SDL_KEYUP:
		keys[event->key.keysym.sym] = false;
		break;
	}
}

bool Keyboard::IsKeyPressed(SDL_KeyCode keyCode) //Thanks for the free warning SDL.
{
	if (keys[keyCode])
		return true;

	return false;
}
