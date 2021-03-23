#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <SDL.h>
namespace Core
{
	struct Vector2
	{
		Vector2();
		Vector2(float x, float y);
		~Vector2();

		static float CalculateDistance(Vector2 vectorOne, Vector2 vectorTwo);
		static Vector2 SubstractVectors(Vector2 vectorOne, Vector2 vectorTwo);

		float CalculateDistance(Vector2 vector);
		SDL_Rect ToRect();
		SDL_Rect ToRect(int w, int h);

		float x;
		float y;
	};
}

#endif