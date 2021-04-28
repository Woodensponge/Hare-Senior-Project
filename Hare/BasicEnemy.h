#ifndef BASIC_ENEMY_H_
#define BASIC_ENEMY_H_

#include "Entity.h"

namespace Hare
{
	namespace Entities
	{
		struct BasicEnemy : Entity
		{
			BasicEnemy();
			BasicEnemy(float x, float y);
			BasicEnemy(int flags);
			BasicEnemy(float x, float y, int flags);
			~BasicEnemy();

			void Update();
		};
	}
}

#endif