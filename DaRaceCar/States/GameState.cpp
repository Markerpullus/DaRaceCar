#include "GameState.h"

void GameState::Init()
{
	carTexture.loadFromFile("Assets/car.png");
	car.setTexture(carTexture);
	car.setScale(2, 2);
	car.setOrigin(64, 64);
	car.setPosition(128, 128);
}

void GameState::Update()
{
	window->draw(car);
}
