//
// Created by John on 17/1/2024 AD.
//

#include "../header/SnakeSection.h"

SnakeSection::SnakeSection(sf::Vector2f startPosition) {
    section.setSize(Vector2f(20,20));
    section.setFillColor(Color::Green);
    section.setPosition(startPosition);
    position = startPosition;
}

Vector2f SnakeSection::getPosition() {
    return position;
}

void SnakeSection::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
}

RectangleShape SnakeSection::getShape() {
    return section;
}

void SnakeSection::Update() {
    section.setPosition(position);
}