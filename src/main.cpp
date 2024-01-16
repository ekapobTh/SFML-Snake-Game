#include <SFML/Graphics.hpp>
#include "../include/State.h"

int main()
{
    auto window = sf::RenderWindow{ { 200, 200 }, "Snake Game" };
    window.setFramerateLimit(144);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}