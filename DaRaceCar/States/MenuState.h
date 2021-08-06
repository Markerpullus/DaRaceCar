#pragma once

#include "State.h"

class MenuState : public State
{
private:
	sf::Text menuText;
	sf::Font font;

	sf::Texture convertibleTexture;
	sf::Sprite convertible;

	sf::RectangleShape button;
	sf::Text buttonText;

	sf::View camera;

public:
	MenuState();
	~MenuState() = default;

	virtual void Update() override;
};

