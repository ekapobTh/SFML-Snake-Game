//
// Created by John on 17/1/2024 AD.
//

#include "../header/Fruit.h"

Fruit::Fruit() {
    Vector2f startingPosition(Vector2f(400,300));
    sprite.setSize(Vector2f(20,20));
    sprite.setFillColor(Color::Red);
    sprite.setPosition(startingPosition);
}

void Fruit::setPosition(sf::Vector2f newPosition) {
    sprite.setPosition(newPosition);
}

RectangleShape Fruit::getSprite(){
    return sprite;
}