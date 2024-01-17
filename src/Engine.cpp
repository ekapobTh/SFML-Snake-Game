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

    NewSnake();
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

void Engine::Run() {
    Clock clock;

    while(window.isOpen()) {
        Time dt = clock.restart();
        timeSinceLastMove += dt;

        Input();
        Update();
        Draw();
    }
}