//
// Created by John on 16/1/2024 AD.
//

#include "../header/Engine.h"

void Engine::Draw()
{
    window.clear(Color::Black);

    window.draw(fruit.getSprite());

    for(auto & s : snake)
    {
        window.draw(s.getShape());
    }

    window.display();
}