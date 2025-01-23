//
// Created by Wojtek on 23.01.2025.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/RectangleShape.hpp>

#include "CONFIG.h"

/*
 * Each entity which is basically a column has:
    * its constant width = chunkWidth
    * height which is = entityHeight

 */
class Entity : public sf::Drawable{
private:
    const float chunkWidth = ENTITY_WIDTH;
    float entityHeight;
    float posX, posY;
    sf::RectangleShape column;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Entity() = default;
    Entity(float height, float posX);

};




#endif //ENTITY_H
