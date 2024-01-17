//
// Created by John on 16/1/2024 AD.
//

#ifndef CMAKESFMLPROJECT_ENGINE_H
#define CMAKESFMLPROJECT_ENGINE_H

#endif //CMAKESFMLPROJECT_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;
using namespace std;

class Engine
{
private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned  int FPS = 60;
    static const Time TimePerFrame;

public:
    Engine();

    void Input();

    void Draw();

    void Run();
};