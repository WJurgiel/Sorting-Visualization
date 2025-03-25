//
// Created by Wojtek on 24.03.2025.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <Entity.h>
#include <memory>


class EntityManager {
    std::vector<Entity> entities;
    float posX;
    std::unique_ptr<int[]> randomHeights;
public:
    EntityManager();
    ~EntityManager() = default;
    void generateEntities();
    std::vector<Entity>& getEntities();
};



#endif //ENTITYMANAGER_H
