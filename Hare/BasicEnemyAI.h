#ifndef BASIC_ENEMY_AI_H_
#define BASIC_ENEMY_AI_H_

#include /*fucking*/ "Entity.h"

namespace Hare
{
	namespace EntityAI
	{
		struct BasicEnemyAI
		{
			BasicEnemyAI(Entity* basicEnemy);
			~BasicEnemyAI();

			void Update();

		private:
			Entity* basicEnemy;
		};
	}
}

#endif