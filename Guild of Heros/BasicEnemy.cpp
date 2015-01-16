#include "BasicEnemy.h"

#include <stdlib.h>
#include <time.h>

BasicEnemy::BasicEnemy(sf::Texture *tex, int x, int y) : Entity(tex, x, y)
{
	srand(time(NULL));
}


BasicEnemy::~BasicEnemy()
{
}


bool BasicEnemy::update(long dt)
{
	if (!level) return false;

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	int dir = rand() % 4;
	
	if (level->isPassable(x + dx[dir], y + dy[dir])) {
		x += dx[dir];
		y += dy[dir];
	}

	sprite.setPosition(x * 32, y * 32);
	printf("%d,%d\n", x,y);
	return true;
}