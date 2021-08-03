#include "DaCar.h"

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f

DaCar::DaCar(b2World* w)
	: world(w)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(256.0f * W2B, 600.0f * W2B);
	body = world->CreateBody(&bodyDef);
	bodyShape.SetAsBox(81.0f * W2B, 51.0f * W2B);
	bodyFixtureDef.shape = &bodyShape;
	bodyFixtureDef.density = 1.0f;
	bodyFixtureDef.friction = 0.2f;
	bodyFixtureDef.restitution = 0.3f;
	body->CreateFixture(&bodyFixtureDef);
	body->SetLinearDamping(0.0f);
	body->SetAngularVelocity(2.0f);
}