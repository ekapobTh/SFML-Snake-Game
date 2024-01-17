//
// Created by John on 16/1/2024 AD.
//

#ifndef CMAKESFMLPROJECT_ENGINE_H
#define CMAKESFMLPROJECT_ENGINE_H

#endif //CMAKESFMLPROJECT_ENGINE_H

#include "../header/SnakeSection.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Engine
{
private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned  int FPS = 60;
    static const Time TimePerFrame;

    vector<SnakeSection> snake;

public:
    Engine();

    void Input();

    void Draw();

    void NewSnake();
    void AddSnakeSection();

    void Run();
};