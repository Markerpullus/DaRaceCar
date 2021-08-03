#include <SFML\Graphics.hpp>
#include <box2d/box2d.h>

#include "Map.h"
#include "States/MenuState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");
    State::window = &window;
    State::SetActiveState(States::Menu);
    
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

        window.clear();
        State::GetCurrentState()->Update();
        window.display();
    }
    State::CleanUp();

    return 0;
}