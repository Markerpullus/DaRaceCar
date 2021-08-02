#include "Map.h"

Map::Map(std::string textureFile, std::string collisionMapFile)
{
	// Load from files
	
	texture.loadFromFile(textureFile);
	setTexture(texture);
}
