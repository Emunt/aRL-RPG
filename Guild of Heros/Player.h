#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Level.h"

class Player : public Entity
{
public:
	Player(sf::Texture *tex, int x, int y);
	~Player();

	bool update(long dt);

private:
	long timeSinceUpdate;
};

