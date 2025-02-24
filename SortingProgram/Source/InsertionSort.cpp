//
// Created by Wojtek on 24.02.2025.
//

#include "InsertionSort.h"

InsertionSort::InsertionSort(SortVisualizer &visualizer, std::vector<Entity> &entities) : Sort(visualizer, entities) {
}

void InsertionSort::sort() {
    int n = NUM_ENTITIES;
    for(int i = 1; i < n; i++) {
        int insertId = i;
        float currentValue = entities[i].getEntityHeight();
        while(insertId - 1 >= 0 && entities[insertId - 1].getEntityHeight() > currentValue) {
            visualizer.swapEntities(entities, insertId, insertId-1);
            SortVisualizer::changeEntitiesColor(entities[insertId], entities[insertId-1], sf::Color::Cyan);
            insertId--;
        }
    }
}
