#include "Map.h"

#include <iostream>
#include <fstream>

#define W2B 0.0625f
#define B2W 16.0f

void tokenize(std::string& str, char delim, std::vector<float>& out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(W2B * std::stof(str.substr(start, end - start)));
	}
}

Map::Map(b2World* w)
	: world(w)
{
	texture.loadFromFile("Assets/map.png");
	mapSprite.setTexture(texture);
	mapSprite.setOrigin(3002, 360);
	mapSprite.setPosition(3000, 0);

	mapBodyDef.position.Set(3000.0f * W2B, 0.0f * W2B);
	mapBody = world->CreateBody(&mapBodyDef);
	mapBody->SetUserData("map");
}

void Map::LoadFromFile(std::string file)
{
	std::ifstream stream(file);

	std::string line;
	int count = 0;
	while (getline(stream, line))
	{
		if (line.size() == 0)
			continue;
		char d = ',';
		std::vector<float> coords;
		tokenize(line, d, coords);

		std::vector<b2Vec2> shapeCoords;
		b2PolygonShape shape;
		b2FixtureDef fixtureDef;
		for (int i = 0; i < coords.size(); i += 2)
		{
			shapeCoords.push_back(b2Vec2(coords.at(i),
				-coords.at(i+1)));
		}
		shape.Set(&shapeCoords[0], shapeCoords.size());
		mapShapes.push_back(shape);
		fixtureDef.shape = &mapShapes[count];
		fixtureDef.friction = 1.0f;
		mapFixtureDefs.push_back(fixtureDef);
		mapBody->CreateFixture(&mapFixtureDefs[count]);
		count++;
	}
}