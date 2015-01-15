#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <fstream>


class TexturePool
{
public:
	TexturePool();
	~TexturePool();
	
	bool loadFromFile(std::string filename) {
		std::ifstream file(filename);

		if (!file) return false;

		std::string name;
		std::string path;
		while (true) {
			file >> name;
			file >> path;
			if (file.eof()) break;
			add(name, path);
			
		}

		return true;
	}

	void add(std::string name, std::string path);
	sf::Texture *get(std::string name);

private:
	std::map<std::string, sf::Texture*> textureMap;
};

