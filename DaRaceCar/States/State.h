#pragma once

#include <SFML/Graphics.hpp>

enum class States
{
	Menu = 0,
	Game = 1
};

class State
{
public:
	State() = default;
	virtual ~State() = default;

	virtual void Update() = 0;

	static sf::RenderWindow* window;

	States type;
	bool changeState = false;
};

