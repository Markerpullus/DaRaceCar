#include "Button.h"

Button::Button()
{
	button.setSize(sf::Vector2f(300, 150));
	button.setFillColor(sf::Color::Red);

	font.loadFromFile("Assets/Candal.ttf");
	buttonText.setFont(font);
	buttonText.setCharacterSize(40);
	buttonText.setFillColor(sf::Color::Black);
}

void Button::SetSize(float x, float y)
{
	button.setSize(sf::Vector2f(x, y));
	button.setOrigin(x / 2.0f, y / 2.0f);
}

void Button::SetText(std::string text)
{
	buttonText.setString(text);
	sf::FloatRect textRect = buttonText.getLocalBounds();
	buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	sf::FloatRect buttonRect = button.getGlobalBounds();
	buttonText.setPosition(buttonRect.left + buttonRect.width / 2.0f,
		buttonRect.top + buttonRect.height / 2.0f);
}

void Button::SetCallBack(std::function<void()> callBack)
{
	callBackOnClick = callBack;
}

void Button::CheckStatus()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		|| button.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition()))
	{
		callBackOnClick();
	}
}
