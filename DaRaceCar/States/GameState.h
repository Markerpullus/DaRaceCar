#pragma once

#include <chrono>

#include <box2d/box2d.h>

#include "State.h"
#include "../DaCar.h"
#include "../Map.h"

class ContactListener : public b2ContactListener
{
	virtual void BeginContact(b2Contact* contact) override;

	virtual void EndContact(b2Contact* contact) override;
};

class GameState : public State
{
private:
	b2World* world;
	
	Map* map;
	DaCar* daCar;

	ContactListener contactListener;

	sf::View camera;
	sf::Texture flagTexture;
	sf::Sprite finishFlag;
	sf::Font font;
	sf::Text timerText;

	std::chrono::steady_clock::time_point begin;
	std::chrono::duration<double> elapsed;

public:
	GameState();
	virtual ~GameState() override;

	virtual void Update() override;
};

