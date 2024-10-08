#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#undef main

struct Sprite
{
	Sprite();
	Sprite(SDL_Texture* texture);
	Sprite(SDL_Texture* texture, double x, double y);
	Sprite(SDL_Texture* texture, double x, double y, int w, int h);
	Sprite(SDL_Texture* texture, double x, double y, SDL_Rect size);
	Sprite(SDL_Texture* texture, SDL_Rect size);

	Sprite(const char* imageName);
	Sprite(const char* imageName, double x, double y);
	Sprite(const char* imageName, double x, double y, int w, int h);
	Sprite(const char* imageName, double x, double y, SDL_Rect size);
	Sprite(const char* imageName, SDL_Rect size);

	~Sprite();

	void SetPosition(double x, double y);
	void SetPosition(SDL_Rect rect);
	void SetSize(SDL_Rect size);
	void SetSize(int w, int h);
	void SetPosAndSize(int x, int y, int w, int h);
	void SetPosAndSize(SDL_Rect rect);
	void SetSourceRectangle(SDL_Rect sourceRect);
	void SetTexture(SDL_Texture* texture);
	void SetTextureFromSurface(SDL_Surface* surface);
	void Update();

	double x = 0;
	double y = 0;

	int w = 640;
	int h = 480;
	int layer = 0;

	bool ignoreCamera = false;				//Don't move the sprite according to a camera.

	SDL_Rect sourceRect;
	SDL_Rect size;
	SDL_Texture* texture;
};

#endif