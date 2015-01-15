#include "Player.h"


Player::Player(sf::Texture *tex, int x, int y)
{
	setTexture(tex);
	setPosition(x, y);
	timeSinceUpdate = 0;
}


Player::~Player()
{
}

void Player::setLevel(Level *level_)
{
	level = level_;
}

void Player::setTexture(sf::Texture *tex)
{
	sprite.setTexture(*tex);
}

void Player::setPosition(int x_, int y_)
{
	x = x_;
	y = y_;

	sprite.setPosition(x * 32, y * 32);
}

sf::Vector2i Player::getPosition()
{
	return sf::Vector2i(x, y);
}

sf::Vector2f Player::getWindowPosition()
{
	return sf::Vector2f(x*32, y*32);
}

void Player::update(long dt)
{
	if (!level) return;
	timeSinceUpdate += dt;

	if (timeSinceUpdate < 100) return;
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

	sprite.setPosition(x * 32, y * 32);
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}