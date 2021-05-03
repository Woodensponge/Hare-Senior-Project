#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <SDL.h>
#include <string>

namespace Core
{
	struct Vector2
	{
		Vector2();
		Vector2(float x, float y);
		~Vector2();

		Vector2 operator-(const Vector2& vector)
		{
			Vector2 result = Vector2();
			result.x = this->x - vector.x;
			result.y = this->y - vector.y;

			return result;
		}

		Vector2 operator*(const float& value)
		{
			Vector2 result = Vector2();
			result.x = this->x * value;
			result.y = this->y * value;

			return result;
		}

		bool operator==(const Vector2& vector)
		{
			if (this->x == vector.x
				&& this->y == vector.y)
			{
				return true;
			}

			return false;
		}

		bool operator!=(const Vector2& vector)
		{
			if (this->x == vector.x
				&& this->y == vector.y)
			{
				return false;
			}

			return true;
		}

		static float CalculateDistance(Vector2 vectorOne, Vector2 vectorTwo);
		static Vector2 SubstractVectors(Vector2 vectorOne, Vector2 vectorTwo);

		std::string ToString();
		SDL_Rect ToRect();
		SDL_Rect ToRect(int w, int h);

		float x;
		float y;
	};
}

#endif