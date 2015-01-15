#pragma once
#include <SFML\Graphics.hpp>
#include "Level.h"
class Player
{
public:
	Player(sf::Texture *tex, int x, int y);
	~Player();

	void setLevel(Level *level);

	void setTexture(sf::Texture *tex);
	void setPosition(int x, int y);
	sf::Vector2i getPosition();
	sf::Vector2f getWindowPosition();

	void update(long dt);
	void render(sf::RenderWindow &window);

private:
	int x, y;
	sf::Sprite sprite;
	Level *level;
	long timeSinceUpdate;
};

