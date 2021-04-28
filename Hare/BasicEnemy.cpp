#include "BasicEnemy.h"

using namespace Hare::Entities;

BasicEnemy::BasicEnemy() : BasicEnemy::BasicEnemy(0, 0, 0)
{
}

BasicEnemy::BasicEnemy(float x, float y) : BasicEnemy::BasicEnemy(x, y, 0)
{
}

BasicEnemy::BasicEnemy(int flags) : BasicEnemy::BasicEnemy(0, 0, flags)
{
}

BasicEnemy::BasicEnemy(float x, float y, int flags)
{
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::Update()
{
}
