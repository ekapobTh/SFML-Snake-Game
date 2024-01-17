//
// Created by John on 17/1/2024 AD.
//

#include "../header/Engine.h"

void Engine::Input()
{
    Event event{};

    // Closing
    while(window.pollEvent(event))
    {
        if(event.type == Event::Closed)
            window.close();
    }

    // Input
    if(event.type == Event::KeyPressed)
    {
        if(Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();
    }
}