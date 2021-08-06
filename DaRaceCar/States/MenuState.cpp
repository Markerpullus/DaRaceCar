#include "MenuState.h"

#include <iostream>

MenuState::MenuState()
{
	type = States::Menu;
	camera = sf::View(sf::Vector2f(640, 360), sf::Vector2f(1280, 720));
	window->setView(camera);
	
	font.loadFromFile("Assets/Candal.ttf");
	menuText.setFont(font);
	menuText.setCharacterSize(50);
	menuText.setFillColor(sf::Color::Blue);
	menuText.setString("DaRaceCar");
	menuText.setPosition(500, 100);

	convertibleTexture.loadFromFile("Assets/dababy.png");
	convertible.setTexture(convertibleTexture);
	convertible.setOrigin(250, 250);
	convertible.setPosition(640, 360);
	convertible.setScale(1.4f, 1.4f);

	button.setFillColor(sf::Color::Red);
	button.setSize(sf::Vector2f(300, 150));
	button.setPosition(500, 550);
	buttonText.setFont(font);
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setCharacterSize(40);
	buttonText.setString("Start");
	buttonText.setPosition(580, 600);
}

void MenuState::Update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		|| button.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition()))
	{
		changeState = true;
	}
	window->draw(convertible);
	window->draw(menuText);
	window->draw(button);
	window->draw(buttonText);
}
