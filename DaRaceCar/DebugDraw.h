#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

namespace Debug
{
	void DrawBody(sf::RenderWindow* window, b2Body* body);
}