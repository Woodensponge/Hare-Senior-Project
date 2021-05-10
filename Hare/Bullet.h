#ifndef BULLET_H_
#define BULLET_H_

#include "Entity.h"

namespace Hare
{
	namespace Entities
	{
		struct Bullet : Entity
		{
			Bullet(Level* level);
			Bullet(float x, float y, Level* level);
			Bullet(int flags, Level* level);
			Bullet(float x, float y, int flags, Level* level);
			~Bullet();

			void Update();
		};
	}
}

#endif