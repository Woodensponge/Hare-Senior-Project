#include "Camera.h"
#include "Application.h"
#include "Debug.h"

Camera::Camera()
	:drect(SDL_Rect()), size(SDL_Rect())
{
	SDL_GetWindowMaximumSize(Application::GetWindow(), &drect.w, &drect.h);
	drect.x = 0;
	drect.y = 0;

	InitTexture();
}

Camera::Camera(int width, int height)
	:drect(SDL_Rect()), size(SDL_Rect())
{
	drect.w = width;
	drect.h = height;
	drect.x = 0;
	drect.y = 0;

	InitTexture();
}

Camera::Camera(int width, int height, int viewportWidth, int viewportHeight)
	:drect(SDL_Rect()), size(SDL_Rect())
{
	drect.w = width;
	drect.h = height;
	drect.x = 0;
	drect.y = 0;

	size.w = viewportWidth;
	size.h = viewportHeight;

	InitTexture();
}

Camera::~Camera()
{
	SDL_DestroyTexture(texture);

	DEBUG_LOG << "CAMERA RENDERQUEUE HAS " << renderQueue.size() << " SPRITE(S) LEFT";
	for (Sprite* sprite : renderQueue)
	{
		if (sprite != nullptr)
			delete sprite;
	}
	renderQueue.clear();
	renderQueue.~vector();
}

/*
Clear the cameras texture. This destroys the textures old data and creates a
blank slate.
*/
void Camera::ClearTexture()
{
	SDL_DestroyTexture(texture);
	InitTexture();
}

void Camera::AddToQueue(Line line)
{
	lineQueue.push_back(line);
}

/*
Add a sprite to the cameras queue.
*/
void Camera::AddToQueue(Sprite* sprite)
{
	sprite->Update();
	renderQueue.push_back(sprite);
}

/*
Render all the sprites onto the cameras texture.
Use this method at least once per frame. It can get a bit slow switching render targets.
*/
void Camera::RenderTexture()
{
	SDL_SetRenderTarget(Application::renderer, texture);
	for (Sprite* sprite : renderQueue)
	{
		if (!sprite->ignoreCamera)
		{
			sprite->size.x -= size.x;
			sprite->size.y -= size.y;
		}

		if (sprite->size.x > drect.w					//If the sprite is outside the windows
			|| sprite->size.x + sprite->size.w < 0		//size...
			|| sprite->size.y + sprite->size.h < 0
			|| sprite->size.y > drect.h)
		{
			continue;									//...do not render it.
		}

		SDL_RenderCopy(Application::renderer, sprite->texture, 0, &sprite->size);
	}

	for (Line line : lineQueue)
	{
		SDL_SetRenderDrawColor(Application::renderer, (Uint8)line.r, (Uint8)line.g, (Uint8)line.b, (Uint8)line.a);
		SDL_RenderDrawLine
		(
			Application::renderer,
			line.vectorOne.x - (float)size.x,
			line.vectorOne.y - (float)size.y,
			line.vectorTwo.x - (float)size.x,
			line.vectorTwo.y - (float)size.y
		);
		SDL_SetRenderDrawColor(Application::renderer, 0, 0, 0, 255);
	}

	SDL_SetRenderTarget(Application::renderer, NULL);	//Reset the renderer to default (the window)

	//Clear the render and line queue, make space for the next frame.

	renderQueue.clear();
	lineQueue.clear();
}

/*
Sets the cameras size.
*/
void Camera::SetSize(int width, int height)
{
	drect.w = width;
	drect.h = height;
}

/*
Set where the camera is looking at. Sprites with ignoreCamera on will not be affected.
*/
void Camera::SetViewPosition(int x, int y)
{
	size.x = x;
	size.y = y;
}

void Camera::InitTexture()
{
	texture = SDL_CreateTexture
	(
		Application::renderer, 
		SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_TARGET, 
		drect.w, 
		drect.h
	);

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
}
