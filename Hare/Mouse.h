#ifndef MOUSE_H_
#define MOUSE_H_

#include "Vector2.h"

#define MOUSE_X() Mouse::GetMouseX()
#define MOUSE_Y() Mouse::GetMouseY()

struct Mouse 
{
	static void UpdateMouse();
	static inline int GetMouseX()				{ return x; };
	static inline int GetMouseY()				{ return y; };
	static inline Core::Vector2 GetVector2()	{ return pos; };

private:
	static int x;
	static int y;

	static Core::Vector2 pos;
};

#endif