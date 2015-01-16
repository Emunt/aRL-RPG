#include "TexturePool.h"


TexturePool::TexturePool()
{
	texNotFound = new sf::Texture();
}


TexturePool::~TexturePool()
{
}

void TexturePool::add(std::string name, std::string path)
{
	sf::Texture *tex = new sf::Texture;
	tex->loadFromFile(path);
	textureMap.insert(std::pair<std::string, sf::Texture*>(name, tex));

}


sf::Texture *TexturePool::get(std::string name)
{
	if (!textureMap[name]) {
		printf("Error finding texture: %s", name.c_str());

		return texNotFound;
	}
	return textureMap[name];
}