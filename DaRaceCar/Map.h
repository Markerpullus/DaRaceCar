#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Map : public sf::Sprite
{
private:
	sf::Texture texture;
	sf::Texture collisionMap;

public:
	Map(std::string textureFile, std::string collisionMapFile);
	~Map() = default;
};

