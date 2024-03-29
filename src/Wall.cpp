//
// Created by John on 18/1/2024 AD.
//

#include "../header/Wall.h"

Wall::Wall(Vector2f position, Vector2f size) {
    wallShape.setSize(size);
    wallShape.setFillColor(Color::White);
    wallShape.setPosition(position);
}

RectangleShape Wall::getShape() {
    return wallShape;
}