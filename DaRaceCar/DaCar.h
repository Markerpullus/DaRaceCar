#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

class DaCar : public sf::Sprite
{
private:
	b2World* world;

	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape bodyShape;
	b2FixtureDef bodyFixtureDef;

	b2BodyDef wheelsDef;
	b2Body* wheels;
	b2CircleShape wheelsShape;
	b2FixtureDef wheelsFixtureDef;

	b2JointDef axleDef;
	b2Joint* axle;

public:
	DaCar(b2World* w);
	~DaCar() = default;

	inline b2Body* GetBody() { return body; }
	inline b2Body* GetWheels() { return wheels; }
	inline b2Joint* GetAxle() { return axle; }
};

