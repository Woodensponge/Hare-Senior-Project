#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Sprite.h"
#include <vector>

struct TextureManager
{
	static SDL_Texture* LoadTexture(const char* imagePath);
	static SDL_Texture* LoadTextureFromSurface(SDL_Surface* texture);
private:
	static std::vector<SDL_Texture*> textures;
};

#endif