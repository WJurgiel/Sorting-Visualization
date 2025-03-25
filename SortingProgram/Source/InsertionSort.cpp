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
        arrayAccessesCount++;
        while(insertId - 1 >= 0 && entities[insertId - 1].getEntityHeight() > currentValue) {
            arrayAccessesCount++;
            comparisionsCount++;
            visualizer.swapEntities(entities, insertId, insertId-1);
            arrayAccessesCount += 3;
            SortVisualizer::changeEntitiesColor(entities[insertId], entities[insertId-1], sf::Color::Cyan);
            insertId--;

            visualizer.updateCounters(comparisionsCount,arrayAccessesCount);
        }
        arrayAccessesCount += 1;
        visualizer.updateCounters(comparisionsCount,arrayAccessesCount);

    }
}
