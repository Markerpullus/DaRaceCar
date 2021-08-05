#pragma once

#include <box2d/box2d.h>

#include "State.h"
#include "../DaCar.h"
#include "../Map.h"

class GameState : public State
{
private:
	b2World* world;
	
	Map* map;
	DaCar* daCar;

	sf::View* camera;

public:
	GameState();
	~GameState();

	virtual void Update() override;
};

