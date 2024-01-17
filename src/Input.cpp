//
// Created by John on 17/1/2024 AD.
//

#include "../header/Engine.h"

void Engine::Input() {
    Event event{};

    // Closing
    while(window.pollEvent(event)){
        if(event.type == Event::Closed)
            window.close();
    }

    // Input
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::Escape){
            window.close();
        }

        std::cout << event.key.code << "\n";
        if(event.key.code == 64){
            TogglePause();
        }

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