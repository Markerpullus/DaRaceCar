#pragma once

#include <functional>
#include <string>

#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape button;
	sf::Font font;
	sf::Text buttonText;

	std::function<void()> callBackOnClick;

public:
	Button();
	Button(Button& button) = default;
	~Button() = default;

	void SetSize(float x, float y);

	void SetText(std::string text);

	void SetCallBack(std::function<void()> callBack);

	void CheckStatus();

	friend class MenuState;
};

