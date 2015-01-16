#include "Entity.h"


Entity::Entity(sf::Texture *tex, int x, int y)
{
	setTexture(tex);
	setPosition(x, y);
}


Entity::~Entity()
{
}

void Entity::setLevel(Level *level_)
{
	level = level_;
}

void Entity::setTexture(sf::Texture *tex)
{
	sprite.setTexture(*tex);
}

void Entity::setPosition(int x_, int y_)
{
	x = x_;
	y = y_;

	sprite.setPosition(x * 32, y * 32);
}

sf::Vector2i Entity::getPosition()
{
	return sf::Vector2i(x, y);
}

sf::Vector2f Entity::getWindowPosition()
{
	return sf::Vector2f(x * 32, y * 32);
}

void Entity::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}