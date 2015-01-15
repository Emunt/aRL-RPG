#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <fstream>

#include "Tile.h"
#include "TexturePool.h"

class Level
{
public:
	Level(TexturePool *pool, int width, int height);
	~Level();

	void render(sf::RenderWindow &win);
	virtual void generate(std::string path) = 0;

	bool isPassable(int x, int y);

protected:
	int width, height;
	int pixelsPerTile;
	std::vector<std::vector<Tile> > levelData;
	TexturePool *pool;
};


class OverworldLevel : public Level
{
public:
	OverworldLevel(TexturePool *pool_, int width, int height);
	~OverworldLevel();

	void generate(std::string pathenerate);
};
