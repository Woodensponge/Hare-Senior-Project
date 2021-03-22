#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <map>
#include <SDL_events.h>

struct Keyboard
{
	static void UpdateKeyboard(SDL_Event* event);
	static bool IsKeyPressed(SDL_KeyCode keyCode);

	/*true = key pressed; false = key not pressed*/
	static std::map<int, bool> keys;
};

#endif 