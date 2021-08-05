#include <SFML\Graphics.hpp>

#include "Map.h"
#include "States/MenuState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "DaRaceCar");
    window.setVerticalSyncEnabled(true);
    State::window = &window;
    State::SetActiveState(States::Game);
    
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
        State::GetCurrentState()->Update();
        window.display();
    }
    State::CleanUp();
    

    return 0;
}