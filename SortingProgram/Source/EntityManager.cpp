//
// Created by Wojtek on 24.03.2025.
//

#include "EntityManager.h"

EntityManager::EntityManager() : posX(0) {
    randomHeights = std::make_unique<int[]>(NUM_ENTITIES);
}

void EntityManager::generateEntities() {
    for(int id = 0; id < NUM_ENTITIES; id++) {
        randomHeights[id] = (rand()% static_cast<int>(WINDOW_HEIGHT) + 40 - VERTICAL_OFFSET) ;
        entities.emplace_back(
            id,
            static_cast<float>(randomHeights[id]),
            posX
            );
        posX += ENTITY_WIDTH + HORIZONTAL_OFFSET;
    }
}
std::vector<Entity>& EntityManager::getEntities() {
    return entities;
}
