#include "MenuState.h"
#include "GameState.h"

State* State::currentState = nullptr;

sf::RenderWindow* State::window = nullptr;

void State::SetActiveState(States state)
{
	if (currentState != nullptr)
		delete currentState;
	switch (state)
	{
	case States::Menu:
		currentState = new MenuState();
		break;
	case States::Game:
		currentState = new GameState();
		break;
	}
}