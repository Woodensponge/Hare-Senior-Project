#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Sprite.h"
#include <vector>

struct TextureManager
{
	static SDL_Texture* LoadTexture(const char* imagePath);
	static SDL_Texture* LoadTextureFromSurface(SDL_Surface* texture);
	static void RenderSprite(Sprite* sprite);
	static void RenderQueue();
	static void ClearQueue();
	static void DestroyQueue();

	static std::vector<Sprite*> renderQueue;

private:
	struct SortSpriteLayer_LessThan
	{
		inline bool operator() (const Sprite* spriteOne, const Sprite* spriteTwo)
		{
			return (spriteOne->layer < spriteTwo->layer);
		}
	};
};

#endif