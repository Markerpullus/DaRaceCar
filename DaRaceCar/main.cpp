#include <SFML\Graphics.hpp>

#include "States/MenuState.h"
#include "States/GameState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "DaRaceCar");
    window.setVerticalSyncEnabled(true);
    State::window = &window;
    State* currentState;
    currentState = new MenuState;
    
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            switch (e.type)
            {
            case sf::Event::EventType::Closed:
                window.close();
                break;
            }
        }

        window.clear(sf::Color(135, 206, 250));
        if (currentState->changeState)
        {
            
            switch (currentState->type)
            {
            case States::Game:
                delete currentState;
                currentState = new MenuState;
                break;
            case States::Menu:
                delete currentState;
                currentState = new GameState;
                break;
            }
        }
        currentState->Update();
        window.display();
    }
    
    return 0;
}