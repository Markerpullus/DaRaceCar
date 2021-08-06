#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Map
{
private:
	b2World* world;

	b2BodyDef mapBodyDef;
	b2Body* mapBody;
	std::vector<b2PolygonShape> mapShapes;
	std::vector<b2FixtureDef> mapFixtureDefs;

	sf::Texture texture;
	sf::Sprite mapSprite;

	int mapIdentifier = 2;

public:
	Map(b2World* w);
	~Map() = default;

	inline b2Body* GetBody() { return mapBody; }

	void LoadFromFile(std::string file);

	friend class GameState;
};

