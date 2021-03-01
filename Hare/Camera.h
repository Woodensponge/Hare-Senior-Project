#ifndef CAMERA_H_
#define CAMERA_H_

#include <SDL.h>

struct Camera
{
	Camera();
	Camera(int width, int height);
	~Camera();

	inline void SetWidth(int width)		{ rect.w = width; };
	inline void SetHeight(int height)	{ rect.h = height; };
	inline void SetRect(SDL_Rect rect)	{ rect = rect; };
	void SetSize(int width, int height);
	void SetPosition(int x, int y);
	void Update();

	SDL_Rect rect;
};

#endif