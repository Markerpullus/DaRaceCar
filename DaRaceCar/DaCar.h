#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

class DaCar
{
private:
	sf::Texture bodyTexture;
	sf::Texture wheelsTexture;

	b2World* world;

	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape bodyShape;
	b2FixtureDef bodyFixtureDef;

	b2BodyDef wheel1Def;
	b2BodyDef wheel2Def;
	b2Body* wheel1;
	b2Body* wheel2;
	b2CircleShape wheelShape;
	b2FixtureDef wheelFixtureDef;

	b2JointDef axleDef;
	b2Joint* axle;

public:
	DaCar(b2World* w);
	~DaCar() = default;

	sf::Sprite bodySprite;
	sf::Sprite wheel1Sprite;
	sf::Sprite wheel2Sprite;
	inline b2Body* GetBody() { return body; }
	inline b2Body* GetWheel1() { return wheel1; }
	inline b2Body* GetWheel2() { return wheel2; }
	inline b2Joint* GetAxle() { return axle; }

	void Update();
};

