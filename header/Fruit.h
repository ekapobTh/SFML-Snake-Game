//
// Created by John on 17/1/2024 AD.
//

#ifndef CMAKESFMLPROJECT_FRUIT_H
#define CMAKESFMLPROJECT_FRUIT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Fruit {
private:
    RectangleShape sprite;

public:
    Fruit();

    void setPosition(Vector2f newPosition);
    RectangleShape getSprite();
};


#endif //CMAKESFMLPROJECT_FRUIT_H
