#include "Tile.h"


Tile::Tile(sf::Texture *tex, int x, int y)
{
	sprite.setTexture(*tex);
	setRenderPosition(x, y);
	passable = true;
}


Tile::~Tile()
{
}


bool Tile::isPassable()
{
	return passable;
}

void Tile::setPassable(bool pass)
{
	passable = pass;
}

sf::Sprite Tile::getSprite()
{
	return sprite;
}

void Tile::setSprite(sf::Sprite sprt)
{
	sprite = sprt;
}

void Tile::setRenderPosition(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x * 32, y * 32));
}
