//
// Created by Wojtek on 23.01.2025.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

#include "CONFIG.h"

/*
 * Each entity which is basically a column has:
    * its constant width = chunkWidth
    * height which is = entityHeight

 */
class Entity : public sf::Drawable{
private:
    int id;
    const float chunkWidth = ENTITY_WIDTH;
    float entityHeight;
    float posX, posY;
    sf::RectangleShape column;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Entity() = default;
    Entity(int id, float height, float posX);
    Entity(Entity&& other) noexcept
    : id(other.id), entityHeight(other.entityHeight), posX(other.posX), posY(other.posY),
      column(std::move(other.column)) {
    }
    Entity& operator=(Entity&& other) noexcept {
        if(this!= &other) {
            id = other.id;
            posX = other.posX;
            posY = other.posY;
            entityHeight = other.entityHeight;

            column = std::move(other.column);
        }
        return *this;
    }
    float& getEntityHeight();
    void updateColumn() {
        column.setPosition(posX, posY);
        column.setSize({chunkWidth, entityHeight});
    }
    void changeColor() {
        column.setFillColor(sf::Color::Red);
    }
    int getID() const {
        return id;
    }
    void setPosX(const float x) {
        posX = x;
    }
    float getPosX() const {
        return posX;
    }
    friend std::ostream& operator<<(std::ostream& os, const Entity& e) {
        os << "I am: ["<< e.id << "] height: " << e.entityHeight <<
            ", my pos: (" << e.posX << ", " << e.posY << ")"<<
                "rect pos: (" << e.column.getPosition().x << ", " << e.column.getPosition().y << ")\n";
        return os;
    }
};


#endif //ENTITY_H
