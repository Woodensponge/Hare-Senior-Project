#ifndef CAMERA_H_
#define CAMERA_H_

#include "Line.h"
#include "Sprite.h"

#include <SDL.h>
#include <vector>

struct Camera
{
	Camera();
	Camera(int width, int height);
	Camera(int width, int height, int viewportWidth, int viewportHeight);
	~Camera();

	inline void SetWidth(int width)		{ drect.w = width; };
	inline void SetHeight(int height)	{ drect.h = height; };
	inline void SetRect(SDL_Rect drect)	{ drect = drect; };
	void ClearTexture();
	void AddToQueue(Line line);
	void AddToQueue(Sprite* sprite);
	void RenderTexture();
	void SetSize(int width, int height);
	void SetViewPosition(int x, int y);

	SDL_Rect size;
	SDL_Rect drect;
	SDL_Texture* texture;

private:
	void InitTexture();

	std::vector<Sprite*> renderQueue;
	std::vector<Line> lineQueue;
};

#endif