#include "GameState.h"
#include "../DebugDraw.h"

#include <iostream>

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f

class ContactListener : public b2ContactListener
{
	virtual void BeginContact(b2Contact* contact) override
	{
		b2Body* bodyA = contact->GetFixtureA()->GetBody();
		b2Body* bodyB = contact->GetFixtureB()->GetBody();
	}

	virtual void EndContact(b2Contact* contact) override
	{

	}
};

GameState::GameState()
{
	b2Vec2 gravity(0.0f, 400.0f * W2B);
	world = new b2World(gravity);
	world->SetContactListener(new ContactListener);

	map = new Map(world);
	map->LoadFromFile("Assets/mapHitBox.txt");
	daCar = new DaCar(world);

	camera = new sf::View(daCar->bodySprite.getPosition(), sf::Vector2f(1280, 720));
	window->setView(*camera);
}

GameState::~GameState()
{
	delete daCar;
	delete world;
}

void GameState::Update()
{
	world->Step(1.0f / 60.0f, 6, 2);
	daCar->Update();

	camera->setCenter(daCar->bodySprite.getPosition());
	window->setView(*camera);
	window->draw(daCar->bodySprite);
	window->draw(daCar->wheel1Sprite);
	window->draw(daCar->wheel2Sprite);
	window->draw(map->mapSprite);
	/*
	Debug::DrawBody(window, map->GetBody());
	Debug::DrawBody(window, daCar->GetWheel1());
	Debug::DrawBody(window, daCar->GetWheel2());
	Debug::DrawBody(window, daCar->GetBody());*/
}
