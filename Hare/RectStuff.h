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
		static int RectPenetration(SDL_Rect rectOne, SDL_Rect rectTwo);
	};
}

#endif // !RECT_STUFF_H_
