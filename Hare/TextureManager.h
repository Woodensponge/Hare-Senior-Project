#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Camera.h"
#include "Line.h"
#include "Sprite.h"
#include "Vector2.h"

#include <vector>

struct TextureManager
{
	//Gets the main camera for rendering. Will not be destroyed on its own.
	inline static Camera* GetMainCamera()				{ return mainCamera; };
	//Sets the main camera for rendering. Will not be destroyed on its own.
	inline static void SetMainCamera(Camera* camera)	{ mainCamera = camera; };
	static SDL_Texture* LoadTexture(const char* imagePath);
	static SDL_Texture* LoadTextureFromSurface(SDL_Surface* texture);
	static void RenderLine(float x1, float y1, float x2, float y2);
	static void RenderLine(Core::Vector2 vectorOne, Core::Vector2 vectorTwo);
	static void RenderLine(Line line);
	static void RenderSprite(Sprite* sprite);
	static void RenderQueue();
	static void ClearQueue();
	static void DestroyQueue();

	static std::vector<Sprite*> spriteQueue;
	static std::vector<Line> lineQueue;

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