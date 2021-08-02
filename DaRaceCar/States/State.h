#pragma once

#include <SFML/Graphics.hpp>

enum class States
{
	Menu = 0,
	Game = 1
};

class State
{
protected:
	static State* currentState;

public:
	State() = default;
	~State() = default;

	virtual void Init() = 0;

	virtual void Update() = 0;

	static sf::RenderWindow* window;

	static void SetActiveState(States state);

	inline static State* GetCurrentState() { return currentState; }

	inline static void CleanUp() { delete currentState; }
};

