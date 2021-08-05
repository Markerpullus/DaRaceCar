#include "GameState.h"
#include "../DebugDraw.h"

#include <iostream>

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f

GameState::GameState()
{
	b2Vec2 gravity(0.0f, 400.0f * W2B);
	world = new b2World(gravity);
	groundBodyDef.position.Set(640.0f * W2B, 720.0f * W2B);
	groundBody = world->CreateBody(&groundBodyDef);
	groundBox.SetAsBox(1280.0f * W2B, 10.0f * W2B);
	groundFixtureDef.shape = &groundBox;
	groundFixtureDef.friction = 1.0f;
	groundBody->CreateFixture(&groundFixtureDef);

	daCar = new DaCar(world);
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
	window->draw(daCar->bodySprite);
	window->draw(daCar->wheel1Sprite);
	window->draw(daCar->wheel2Sprite);
	/*
	Debug::DrawBody(window, daCar->GetWheel1());
	Debug::DrawBody(window, daCar->GetWheel2());
	Debug::DrawBody(window, groundBody);
	Debug::DrawBody(window, daCar->GetBody());*/
}
