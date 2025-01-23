//
// Created by Wojtek on 23.01.2025.
//

#include "Entity.h"

#include <SFML/Graphics/RenderTarget.hpp>

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(column,states);
}

Entity::Entity(float height, float posX){
    this->entityHeight = height;
    this->posX = posX;
    this->posY = WINDOW_HEIGHT - this->entityHeight;
    this->column.setSize({this->chunkWidth, entityHeight});
    this->column.setPosition(posX, this->posY);
    this->column.setFillColor(sf::Color::Cyan);
}
