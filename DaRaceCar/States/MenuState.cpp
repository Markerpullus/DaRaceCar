#include "MenuState.h"
#include "../DaCar.h"

#include <iostream>
#include <string>

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

	timerText.setFont(font);
	timerText.setCharacterSize(30);
	timerText.setFillColor(sf::Color::Black);
	timerText.setPosition(950, 300);
	timerText.setString("Best time:"
		+ std::to_string((int)DaCar::bestTime));

	convertibleTexture.loadFromFile("Assets/dababy.png");
	convertible.setTexture(convertibleTexture);
	convertible.setOrigin(250, 250);
	convertible.setPosition(640, 360);
	convertible.setScale(1.4f, 1.4f);

	button.button.setFillColor(sf::Color::Transparent);
	button.SetSize(200, 150);
	button.button.setPosition(640, 600);
	button.SetText("Start");
	button.SetCallBack([this]()
		{
			changeState = true;
		});
}

void MenuState::Update()
{
	button.CheckStatus();
	window->draw(convertible);
	window->draw(menuText);
	window->draw(button.button);
	window->draw(button.buttonText);
	window->draw(timerText);
}
