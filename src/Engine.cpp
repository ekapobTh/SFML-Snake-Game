//
// Created by John on 16/1/2024 AD.
//

#include "../header/Engine.h"

const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine() {
    resolution = Vector2f(800,600);

    window.create(VideoMode(resolution.x,resolution.y), "Snake Game", Style::Default);
    window.setFramerateLimit(FPS);

    speed = 2;
    snakeDirection = Direction::RIGHT;

    timeSinceLastMove = Time::Zero;

    sectionsToAdd = 0;
    NewSnake();
    MoveFruit();

    currentGameState = GameState::RUNNING;
    lastGameState = currentGameState;
}

void Engine::NewSnake() {
    snake.clear();
    snake.emplace_back(Vector2f(100,100));
    snake.emplace_back(Vector2f(80,100));
    snake.emplace_back(Vector2f(60,100));
}

void Engine::AddSnakeSection() {
    Vector2f  newSectionPosition = snake[snake.size()-1].getPosition();
    snake.emplace_back(newSectionPosition);
}

void Engine::MoveFruit() {
    Vector2f fruitResolution = Vector2f (resolution.x/20-2,resolution.y/20-2);
    Vector2f  newFruitLocation;
    bool badLocation = false;
    srand(time(nullptr));

    do {
        badLocation = false;

        newFruitLocation.x = (float)(1+rand() / ((RAND_MAX + 1u) / (int)fruitResolution.x)) * 20;
        newFruitLocation.y = (float)(1+rand() / ((RAND_MAX + 1u) / (int)fruitResolution.y)) * 20;

        for(auto & s : snake) {
            if(s.getShape().getGlobalBounds().intersects(Rect<float>(newFruitLocation.x, newFruitLocation.y, 20, 20))){
                badLocation = true;
                break;
            }
        }
    } while (badLocation);

    fruit.setPosition(newFruitLocation);
}

void Engine::TogglePause() {
    if(currentGameState == GameState::RUNNING){
        lastGameState = currentGameState;
        currentGameState = GameState::PAUSED;
    } else if(currentGameState == GameState::PAUSED){
        currentGameState = lastGameState;
    }
}

void Engine::Run() {
    Clock clock;

    while(window.isOpen()) {
        Time dt = clock.restart();

        if(currentGameState == GameState::PAUSED || currentGameState == GameState::GAMEOVER){
            Input();

            if(currentGameState == GameState::GAMEOVER){
                Draw();
            }

            sleep(milliseconds(2));
            continue;
        }

        timeSinceLastMove += dt;

        Input();
        Update();
        Draw();
    }
}