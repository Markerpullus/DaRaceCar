#pragma once

#include "State.h"

class MenuState : public State
{
private:
	sf::Text menuText;
	sf::Font font;

public:
	MenuState();
	~MenuState() = default;

	virtual void Update() override;
};

