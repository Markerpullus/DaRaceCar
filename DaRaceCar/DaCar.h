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
	b2FixtureDef wheel1FixtureDef;
	b2FixtureDef wheel2FixtureDef;

	b2WheelJointDef axle1Def;
	b2WheelJoint* axle1;
	b2WheelJointDef axle2Def;
	b2WheelJoint* axle2;

	sf::Sprite bodySprite;
	sf::Sprite wheel1Sprite;
	sf::Sprite wheel2Sprite;

	bool inAir;

public:
	DaCar(b2World* w);
	~DaCar() = default;
	
	inline b2Body* GetBody() { return body; }
	inline b2Body* GetWheel1() { return wheel1; }
	inline b2Body* GetWheel2() { return wheel2; }
	inline b2WheelJoint* GetAxle1() { return axle1; }
	inline b2WheelJoint* GetAxle2() { return axle2; }

	void Update();

	friend class GameState;
	friend class ContactListener;
};

