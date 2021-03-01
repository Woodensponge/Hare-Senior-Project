#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Sprite.h"
#include "Camera.h"

#include <vector>

struct TextureManager
{
	//Gets the main camera for rendering. Will not be destroyed on its own.
	inline static Camera* GetCamera()				{ return mainCamera; };
	//Sets the main camera for rendering. Will not be destroyed on its own.
	inline static void SetCamera(Camera* camera)	{ mainCamera = camera; };
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

	//IMPORTANT NOTE:
	//The camera will not be destroyed by TextureManager. Whoever loads the camera must
	//destroy it themselves!
	static Camera* mainCamera;
};

#endif