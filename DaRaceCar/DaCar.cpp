#include "DaCar.h"

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f

DaCar::DaCar(b2World* w)
	: world(w)
{
	// SFML
	bodyTexture.loadFromFile("Assets/body.png");
	wheelsTexture.loadFromFile("Assets/wheels.png");
	bodySprite.setTexture(bodyTexture);
	bodySprite.setOrigin(40.5f, 21.5f);
	bodySprite.setScale(1.9f, 1.9f);

	wheel1Sprite.setTexture(wheelsTexture);
	wheel2Sprite.setTexture(wheelsTexture);
	wheel1Sprite.setOrigin(32, 32);
	wheel2Sprite.setOrigin(32, 32);
	wheel1Sprite.setScale(0.5f, 0.5f);
	wheel2Sprite.setScale(0.5f, 0.5f);

	// Physics
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(256.0f * W2B, 100.0f * W2B);
	body = world->CreateBody(&bodyDef);
	bodyShape.SetAsBox(81.0f * W2B, 43.0f * W2B);
	bodyFixtureDef.shape = &bodyShape;
	bodyFixtureDef.density = 1.0f;
	bodyFixtureDef.friction = 0.4f;
	bodyFixtureDef.restitution = 0.1f;
	body->CreateFixture(&bodyFixtureDef);
	body->SetLinearDamping(0.0f);
	body->SetAngularVelocity(-1.0f);

	wheelShape.m_radius = 18.0f * W2B;
	wheelFixtureDef.shape = &wheelShape;
	wheelFixtureDef.density = 0.4f;
	wheelFixtureDef.friction = 0.9f;
	wheelFixtureDef.restitution = 0.0f;
	
	wheel1Def.type = b2_dynamicBody;
	b2Vec2 bodyPos = body->GetPosition();
	wheel1Def.position.Set(bodyPos.x + 150.0f * W2B, bodyPos.y - 30.0f * W2B);
	wheel1 = world->CreateBody(&wheel1Def);
	wheel1->CreateFixture(&wheelFixtureDef);

	wheel2Def.type = b2_dynamicBody;
	wheel2Def.position.Set(bodyPos.x + 180.0f * W2B, bodyPos.y - 20.0f * W2B);
	wheel2 = world->CreateBody(&wheel2Def);
	wheel2->CreateFixture(&wheelFixtureDef);
}

void DaCar::Update()
{
	b2Vec2 position = B2W * body->GetPosition();
	float rotation = RAD2DEG * body->GetAngle();
	bodySprite.setPosition(position.x, position.y);
	bodySprite.setRotation(rotation);


	position = B2W * wheel1->GetPosition();
	rotation = RAD2DEG * wheel1->GetAngle();
	wheel1Sprite.setPosition(position.x, position.y);
	wheel1Sprite.setRotation(rotation);

	position = B2W * wheel2->GetPosition();
	rotation = RAD2DEG * wheel2->GetAngle();
	wheel2Sprite.setPosition(position.x, position.y);
	wheel2Sprite.setRotation(rotation);
}