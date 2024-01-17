//
// Created by John on 16/1/2024 AD.
//

#ifndef CMAKESFMLPROJECT_ENGINE_H
#define CMAKESFMLPROJECT_ENGINE_H

#endif //CMAKESFMLPROJECT_ENGINE_H

#include "../header/SnakeSection.h"
#include "../header/Fruit.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <deque>

using namespace sf;
using namespace std;

class Engine{
private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned  int FPS = 60;
    static const Time TimePerFrame;

    vector<SnakeSection> snake;

    int snakeDirection;
    deque<int> directionQueue;
    int speed;
    int sectionsToAdd;

    Fruit fruit;

    Time timeSinceLastMove;

    int currentGameState;
    int lastGameState;

public:
    enum Direction { UP, RIGHT, DOWN, LEFT };
    enum GameState { RUNNING, PAUSED, GAMEOVER };
    Engine();

    void Input();
    void AddDirection(int newDirection);
    void Update();

    void Draw();

    void NewSnake();
    void AddSnakeSection();

    void MoveFruit();

    void TogglePause();

    void Run();
};