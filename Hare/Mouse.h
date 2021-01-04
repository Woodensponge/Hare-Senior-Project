#ifndef MOUSE_H_
#define MOUSE_H_

#define MOUSE_X Mouse::GetMouseX()
#define MOUSE_Y Mouse::GetMouseY()

struct Mouse 
{
	static void UpdateMousePosition();
	static inline int GetMouseX() { return x; };
	static inline int GetMouseY() { return y; };

private:
	static int x;
	static int y;
};

#endif