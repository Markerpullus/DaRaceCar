#pragma once

#include "State.h"
#include "../Button.h"

class MenuState : public State
{
private:
	sf::Text menuText;
	sf::Text timerText;
	sf::Font font;

	sf::Texture convertibleTexture;
	sf::Sprite convertible;

	Button button;

	sf::View camera;

public:
	MenuState();
	virtual ~MenuState() override = default;

	virtual void Update() override;
};

