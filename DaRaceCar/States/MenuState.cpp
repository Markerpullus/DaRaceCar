#include "MenuState.h"

void MenuState::Init()
{
	font.loadFromFile("Assets/Candal.ttf");
	menuText.setFont(font);
	menuText.setFillColor(sf::Color::Blue);
	menuText.setString("Test");
	menuText.setPosition(200, 200);
}

void MenuState::Update()
{
	window->draw(menuText);
}
