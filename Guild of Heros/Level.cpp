#include "Level.h"

Level::Level(TexturePool *pool_, int width_, int height_)
{
	pool = pool_;
	width = width_;
	height = height_;
	pixelsPerTile = 32;
}


Level::~Level()
{
}


void Level::render(sf::RenderWindow &win) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			win.draw(levelData[y][x].getSprite());
		}
	}
}

bool Level::isPassable(int x, int y) {
	if (x < 0 || x >= width || y < 0 || y >= width) return false;
	return levelData[y][x].isPassable();
}

OverworldLevel::OverworldLevel(TexturePool *pool_, int width_, int height_) : Level(pool_, width_, height_)
{
	
}


OverworldLevel::~OverworldLevel()
{

}

void OverworldLevel::generate(std::string path)
{
	std::ifstream file(path);

	int n;
	file >> n;

	std::string texMap[127];
	bool passMap[127];

	char character;
	std::string name;
	std::string canPass;
	for (int i = 0; i < n; i++) {
		file >> character;
		file >> name;
		file >> canPass;
		texMap[character] = name;
		passMap[character] = (canPass == "passable");
	}

	file >> width;
	file >> height;
	
	std::string line;
	for (int y = 0; y < height; y++) {
		file >> line;
		std::vector<Tile> row;
		for (int x = 0; x < width; x++) {
			if (texMap[line[x]] != "") {
				Tile t(pool->get(texMap[line[x]]), x, y);
				t.setPassable(passMap[line[x]]);
				row.push_back(t);
			}
			else 
			{
				printf("Error in %s: character not recognised at %d, %d", path.c_str(), x, y);
			}
		}
		levelData.push_back(row);
		
	}
	
}