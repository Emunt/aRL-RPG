#pragma once
#include <SFML/Graphics.hpp>
class Tile
{
public:
	Tile(sf::Texture *tex, int x, int y);
	~Tile();

	bool isPassable();
	void setPassable(bool pass);

	sf::Sprite getSprite();
	void setSprite(sf::Sprite sprite);

	void setRenderPosition(int x, int y);
private:
	bool passable;
	sf::Sprite sprite;
};

