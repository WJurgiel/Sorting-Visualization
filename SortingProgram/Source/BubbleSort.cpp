//
// Created by Wojtek on 24.02.2025.
//

#include "BubbleSort.h"

BubbleSort::BubbleSort(SortVisualizer &visualizer, std::vector<Entity> &entities) : Sort(visualizer, entities) {
}

void BubbleSort::sort() {
    const int n = NUM_ENTITIES;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            SortVisualizer::changeEntitiesColor(entities[j], entities[j+1], sf::Color::Red);
            arrayAccessesCount += 2;
            comparisionsCount += 1;
            if(entities[j].getEntityHeight() > entities[j+1].getEntityHeight()) {
                arrayAccessesCount += 3;
                visualizer.swapEntities(entities, j, j+1);
            }
            visualizer.updateCounters(comparisionsCount, arrayAccessesCount);
            SortVisualizer::changeEntitiesColor(entities[j], entities[j+1], sf::Color::Cyan);
        }
    }
}
