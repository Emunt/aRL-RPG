#pragma once
#include <SFML\Graphics.hpp>
#include "Level.h"

class Entity
{
public:
	Entity(sf::Texture *tex, int x, int y);
	~Entity();

	void setLevel(Level *level);

	void setTexture(sf::Texture *tex);
	void setPosition(int x, int y);
	sf::Vector2i getPosition();
	sf::Vector2f getWindowPosition();

	virtual bool update(long dt) = 0;
	virtual void render(sf::RenderWindow &window);

protected:
	int x, y;
	sf::Sprite sprite;
	Level *level;
};

