#include "Player.h"


Player::Player(sf::Texture *tex, int x, int y) : Entity(tex, x, y)
{
	setTexture(tex);
	setPosition(x, y);
	timeSinceUpdate = 0;
}


Player::~Player()
{
}


bool Player::update(long dt)
{
	if (!level) return false;
	timeSinceUpdate += dt;

	if (timeSinceUpdate < 100) return false;
	timeSinceUpdate = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && level->isPassable(x - 1, y))
	{
		x--;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && level->isPassable(x + 1, y))
	{
		x++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && level->isPassable(x, y-1))
	{
		y--;
	} 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && level->isPassable(x, y+1))
	{
		y++;
	}
	else {
		return false;
	}

	sprite.setPosition(x * 32, y * 32);

	return true;
}