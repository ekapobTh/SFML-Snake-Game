//
// Created by John on 17/1/2024 AD.
//

#ifndef CMAKESFMLPROJECT_SNAKESECTION_H
#define CMAKESFMLPROJECT_SNAKESECTION_H

#include <SFML/Graphics.hpp>

using namespace sf;

class SnakeSection{
private:
    Vector2f position;
    RectangleShape section;

public:
    explicit SnakeSection(Vector2f startPosition);

    Vector2f getPosition();
    void setPosition(Vector2f newPosition);

    RectangleShape getShape();

    void Update();
};


#endif //CMAKESFMLPROJECT_SNAKESECTION_H
