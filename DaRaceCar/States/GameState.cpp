#include "GameState.h"
#include "../DebugDraw.h"

#include <iostream>
#include <string>

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f


void ContactListener::BeginContact(b2Contact* contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();
	int dataA = (int)bodyA->GetUserData().pointer;
	int dataB = (int)bodyB->GetUserData().pointer;
	if ((dataA == 1 && dataB == 2) ||
		(dataA == 2 && dataB == 1))
	{
		DaCar::inAir = false;
	}
}

void ContactListener::EndContact(b2Contact* contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();
	int dataA = (int)bodyA->GetUserData().pointer;
	int dataB = (int)bodyB->GetUserData().pointer;
	if ((dataA == 1 && dataB == 2) ||
		(dataA == 2 && dataB == 1))
	{
		DaCar::inAir = true;
	}
}


GameState::GameState()
{
	type = States::Game;
	b2Vec2 gravity(0.0f, 400.0f * W2B);
	world = new b2World(gravity);
	world->SetContactListener(&contactListener);

	map = new Map(world);
	map->LoadHitBoxFromFile("Assets/level1HitBox.txt");
	daCar = new DaCar(world);

	camera = sf::View(daCar->bodySprite.getPosition(), sf::Vector2f(1280, 720));
	window->setView(camera);

	flagTexture.loadFromFile("Assets/flag.png");
	finishFlag.setTexture(flagTexture);
	finishFlag.setOrigin(60, 430);
	finishFlag.setPosition(5500, 280);
	finishFlag.setScale(0.5f, 0.5f);

	font.loadFromFile("Assets/Candal.ttf");
	timerText.setFont(font);
	timerText.setCharacterSize(40);
	timerText.setFillColor(sf::Color::Black);
	timerText.setPosition(550, 100);

	begin = std::chrono::steady_clock::now();
}

GameState::~GameState()
{
	if (DaCar::bestTime != 0.0f
		&& elapsed.count() < DaCar::bestTime)
	{
		DaCar::bestTime = elapsed.count();
	}
	DaCar::bestTime = elapsed.count();
	delete daCar;
	delete world;
	delete map;
}

void GameState::Update()
{
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	elapsed = now - begin;
	elapsed = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
	timerText.setString(std::to_string((int)elapsed.count()));

	if (daCar->bodySprite.getPosition().x >= 5500)
		changeState = true;
	world->Step(1.0f / 60.0f, 6, 2);
	daCar->Update();

	camera.setCenter(daCar->bodySprite.getPosition());
	window->setView(camera);
	window->draw(daCar->bodySprite);
	window->draw(daCar->wheel1Sprite);
	window->draw(daCar->wheel2Sprite);
	window->draw(map->mapSprite);
	window->draw(finishFlag);

	window->setView(window->getDefaultView());
	window->draw(timerText);
	/*
	Debug::DrawBody(window, map->GetBody());
	Debug::DrawBody(window, daCar->GetWheel1());
	Debug::DrawBody(window, daCar->GetWheel2());
	Debug::DrawBody(window, daCar->GetBody());*/
}
