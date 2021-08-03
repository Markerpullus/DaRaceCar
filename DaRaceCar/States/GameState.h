#pragma once

#include <box2d/box2d.h>

#include "State.h"
#include "../DaCar.h"

class GameState : public State
{
private:
	b2World* world;
	b2BodyDef groundBodyDef;
	b2Body* groundBody;
	b2PolygonShape groundBox;
	
	DaCar* daCar;

	sf::Texture carTexture;

public:
	GameState();
	~GameState();

	virtual void Update() override;
};

