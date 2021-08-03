#include "GameState.h"

#include <iostream>

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f

GameState::GameState()
{
	b2Vec2 gravity(0.0f, 400.0f * W2B);
	world = new b2World(gravity);
	groundBodyDef.position.Set(256.0f * W2B, 720.0f * W2B);
	groundBody = world->CreateBody(&groundBodyDef);
	groundBox.SetAsBox(256.0f * W2B, 10.0f * W2B);
	groundBody->CreateFixture(&groundBox, 0.0f);

	/*
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(256.0f * W2B, 4.0f * W2B);
	body = world->CreateBody(&bodyDef);
	dynamicBox.SetAsBox(81.0f * W2B, 51.0f * W2B);
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.0f;
	fixtureDef.restitution = 0.7f;
	body->CreateFixture(&fixtureDef);
	body->SetLinearDamping(0.0f);
	body->SetAngularVelocity(2.0f);*/

	daCar = new DaCar(world);
	carTexture.loadFromFile("Assets/car.png");
	daCar->setTexture(carTexture);
	daCar->setScale(2, 2);
	daCar->setOrigin(40, 25);
}

GameState::~GameState()
{
	delete daCar;
	delete world;
}

void GameState::Update()
{
	world->Step(1.0f / 60.0f, 6, 2);
	b2Vec2 position = B2W * daCar->GetBody()->GetPosition();
	float rotation = RAD2DEG * daCar->GetBody()->GetAngle();
	daCar->setPosition(position.x, position.y);
	daCar->setRotation(rotation);
	window->draw(*daCar);
}
