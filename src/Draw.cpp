//
// Created by John on 16/1/2024 AD.
//

#include "../header/Engine.h"

void Engine::Draw()
{
    window.clear(Color::Black);

    for (auto & w : wallSections) {
        window.draw(w.getShape());
    }

    window.draw(fruit.getSprite());

    for(auto & s : snake)
    {
        window.draw(s.getShape());
    }

    window.draw(titleText);
    window.draw(currentLevelText);
    window.draw(fruitEatenText);
    window.draw(scoreText);

    if(currentGameState == GameState::GAMEOVER){
        window.draw(gameOverText);
        window.draw(pressEnterText);
    }

    window.display();
}