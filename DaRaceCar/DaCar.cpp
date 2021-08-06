#include "DaCar.h"

#include <algorithm>

#define MAX_SPEED 25.0f

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f

bool DaCar::inAir = false;
double DaCar::bestTime = 0.0f;

DaCar::DaCar(b2World* w)
	: world(w)
{
	// SFML
	bodyTexture.loadFromFile("Assets/body.png");
	wheelsTexture.loadFromFile("Assets/wheels.png");
	bodySprite.setTexture(bodyTexture);
	bodySprite.setOrigin(200.0f, 112.5f);
	bodySprite.setScale(0.5f, 0.5f);

	wheel1Sprite.setTexture(wheelsTexture);
	wheel2Sprite.setTexture(wheelsTexture);
	wheel1Sprite.setOrigin(32, 32);
	wheel2Sprite.setOrigin(32, 32);
	wheel1Sprite.setScale(0.6f, 0.6f);
	wheel2Sprite.setScale(0.6f, 0.6f);

	// Physics
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(256.0f * W2B, 100.0f * W2B);
	body = world->CreateBody(&bodyDef);
	bodyShape.SetAsBox(81.0f * W2B, 43.0f * W2B);
	bodyFixtureDef.shape = &bodyShape;
	bodyFixtureDef.density = 0.02f;
	bodyFixtureDef.friction = 0.4f;
	bodyFixtureDef.restitution = 0.1f;
	body->CreateFixture(&bodyFixtureDef);

	wheelShape.m_radius = 20.0f * W2B;
	wheel1FixtureDef.shape = &wheelShape;
	wheel1FixtureDef.density = 0.2f;
	wheel1FixtureDef.friction = 10.0f;
	wheel1FixtureDef.restitution = 0.0f;
	
	wheel2FixtureDef.shape = &wheelShape;
	wheel2FixtureDef.filter.groupIndex = -8;
	wheel2FixtureDef.density = 0.2f;
	wheel2FixtureDef.friction = 10.0f;
	wheel2FixtureDef.restitution = 0.0f;
	
	wheel1Def.type = b2_dynamicBody;
	b2Vec2 bodyPos = body->GetPosition();
	wheel1Def.position.Set(bodyPos.x + 80.0f * W2B, bodyPos.y + 12.0f * W2B);
	wheel1Def.angularDamping = 0.2f;
	wheel1Def.userData.pointer = (uintptr_t)wheelIdentifier;
	wheel1 = world->CreateBody(&wheel1Def);
	wheel1->CreateFixture(&wheel1FixtureDef);
	
	wheel2Def.type = b2_dynamicBody;
	wheel2Def.position.Set(bodyPos.x - 80.0f * W2B, bodyPos.y + 12.0f * W2B);
	wheel2Def.angularDamping = 0.2f;
	wheel2Def.userData.pointer = (uintptr_t)wheelIdentifier;
	wheel2 = world->CreateBody(&wheel2Def);
	wheel2->CreateFixture(&wheel2FixtureDef);

	axle1Def.bodyA = body;
	axle1Def.bodyB = wheel1;
	axle1Def.localAnchorA = b2Vec2(4.0f, 2.0f);
	axle1Def.localAnchorB = b2Vec2(0, 0);
	b2LinearStiffness(axle1Def.stiffness, axle1Def.damping, 4.0f, 0.2f, axle1Def.bodyA, axle1Def.bodyB);
	axle1Def.collideConnected = false;
	axle1Def.localAxisA = b2Vec2(0, 1);

	axle1 = (b2WheelJoint*)world->CreateJoint(&axle1Def);
	
	axle2Def.bodyA = body;
	axle2Def.bodyB = wheel2;
	axle2Def.localAnchorA = b2Vec2(-4.0f, 2.0f);
	axle2Def.localAnchorB = b2Vec2(0, 0);
	b2LinearStiffness(axle2Def.stiffness, axle2Def.damping, 4.0f, 0.2f, axle2Def.bodyA, axle2Def.bodyB);
	axle1Def.collideConnected = false;
	axle2Def.localAxisA = b2Vec2(0, 1);
	axle2 = (b2WheelJoint*)world->CreateJoint(&axle2Def);

}

void DaCar::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		wheel2->ApplyTorque(100.0f, true);
		if (inAir)
			body->ApplyTorque(200.0f, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		wheel2->ApplyTorque(-100.0f, true);
		if (inAir)
			body->ApplyTorque(-200.0f, true);
	}
	float wheel1speed = wheel1->GetAngularVelocity();
	float wheel2speed = wheel2->GetAngularVelocity();
	if (abs(wheel1speed) > MAX_SPEED)
	{
		wheel1->SetAngularVelocity(wheel1speed / abs(wheel1speed) * MAX_SPEED);
	}
	if (abs(wheel2speed) > MAX_SPEED)
	{
		wheel2->SetAngularVelocity(wheel2speed / abs(wheel2speed) * MAX_SPEED);
	}

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