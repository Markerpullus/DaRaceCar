#include "DebugDraw.h"

#define W2B 0.0625f
#define B2W 16.0f

#define DEG2RAD 0.0174532925199432957f
#define RAD2DEG 57.295779513082320876f

namespace Debug
{
	void DrawBody(sf::RenderWindow* window, b2Body* body)
	{
		for (b2Fixture* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
		{
			b2Shape::Type shapeType = fixture->GetType();
			if (shapeType == b2Shape::e_circle)
			{
				sf::CircleShape circle;
				circle.setFillColor(sf::Color(255, 0, 0, 128));
				b2CircleShape* circleShape = (b2CircleShape*)fixture->GetShape();
				float radius = B2W * circleShape->m_radius;
				b2Vec2 worldPos = B2W * body->GetWorldPoint(circleShape->m_p);
				circle.setOrigin(radius, radius);
				circle.setPosition(worldPos.x, worldPos.y);
				circle.setRadius(radius);
				window->draw(circle);
			}
			else if (shapeType == b2Shape::e_polygon)
			{
				sf::ConvexShape polygon;
				polygon.setFillColor(sf::Color(0, 255, 0, 50));
				b2PolygonShape* polygonShape = (b2PolygonShape*)fixture->GetShape();
				polygon.setPointCount(polygonShape->m_count);
				for (int i = 0; i < polygonShape->m_count; i++)
				{
					b2Vec2 pos = B2W * body->GetWorldPoint(polygonShape->m_vertices[i]);
					polygon.setPoint(i, sf::Vector2f(pos.x, pos.y));
				}
				window->draw(polygon);

			}
		}
	}
}