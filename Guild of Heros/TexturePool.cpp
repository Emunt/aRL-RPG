#include "TexturePool.h"


TexturePool::TexturePool()
{
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
	return textureMap[name];
}