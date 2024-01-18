//
// Created by John on 18/1/2024 AD.
//

#ifndef CMAKESFMLPROJECT_WALL_H
#define CMAKESFMLPROJECT_WALL_H


#include <SFML/Graphics.hpp>

using namespace sf;

class Wall {
private:
    RectangleShape wallShape;

public:
    Wall(Vector2f position, Vector2f size);

    RectangleShape getShape();

};


#endif //CMAKESFMLPROJECT_WALL_H
