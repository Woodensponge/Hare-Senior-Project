#ifndef RECT_STUFF_H_
#define RECT_STUFF_H_

#include "Vector2.h"

#include <SDL_rect.h>

namespace Core
{
	struct RectStuff
	{
		/*
		Returns the value of Rect penetration between two rects. Uses the farthest point inside either Rect.
		Returns -1 on failure.
		*/
		static int OriginPenetration(SDL_Rect rect, SDL_Rect target);
		static int Penetration(SDL_Rect rect, SDL_Rect target);
		static Core::Vector2 FindNearestCornerInOrigin(SDL_Rect rect, SDL_Rect target);
	};
}

#endif // !RECT_STUFF_H_
