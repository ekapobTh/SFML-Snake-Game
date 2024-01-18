//
// Created by John on 17/1/2024 AD.
//

#include "../header/Engine.h"

void Engine::Input() {
    Event event;

    // Closing
    while(window.pollEvent(event)){
        if(event.type == Event::Closed)
            window.close();

        if(event.key.code == Keyboard::Q){
            std::cout << "ASDASDADA\n";
        }

        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::P)) {
                TogglePause();
            }

            if (Keyboard::isKeyPressed(Keyboard::R)) {
                StartTheGame();
            }
        }
    }

    // Input
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::Up){
            AddDirection(Direction::UP);
        }
        else if(event.key.code == Keyboard::Down){
            AddDirection(Direction::DOWN);
        }
        else if(event.key.code == Keyboard::Left){
            AddDirection(Direction::LEFT);
        }
        else if(event.key.code == Keyboard::Right){
            AddDirection(Direction::RIGHT);
        }
    }
}

void Engine::AddDirection(int newDirection) {
    if(directionQueue.empty()) {
        directionQueue.emplace_back(newDirection);
    }
    else{
        if(directionQueue.back() != newDirection){
            directionQueue.emplace_back(newDirection);
        }
    }
}