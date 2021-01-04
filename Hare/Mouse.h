#ifndef MOUSE_H_
#define MOUSE_H_

struct Mouse 
{
	static int x;
	static int y;

	static void UpdateMousePosition();
	static inline int GetMouseX() { return x; };
	static inline int GetMouseY() { return y; };
};

#endif