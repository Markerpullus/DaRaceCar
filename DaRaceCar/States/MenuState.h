#pragma once

#include "State.h"

class MenuState : public State
{
private:
	sf::Text menuText;
	sf::Font font;

public:
	MenuState() = default;
	~MenuState() = default;

	virtual void Init() override;

	virtual void Update() override;
};

