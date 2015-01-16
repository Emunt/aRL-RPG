#pragma once

#include "Entity.h"

class BasicEnemy : public Entity
{
public:
	BasicEnemy(sf::Texture *tex, int x, int y);
	~BasicEnemy();

	bool update(long dt);
private:

};

