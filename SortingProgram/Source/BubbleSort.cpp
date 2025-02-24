//
// Created by Wojtek on 24.02.2025.
//

#include "BubbleSort.h"

BubbleSort::BubbleSort(SortVisualizer &visualizer, std::vector<Entity> &entities) : Sort(visualizer, entities) {
}

void BubbleSort::sort() {
    int comparisions = 0;
    int arrayAccess = 0;
    const int n = NUM_ENTITIES;
    for (int i = 0; i < n-1; i++) {

        for (int j = 0; j < n-i-1; j++) {
            visualizer.updateCounters(comparisions, ++arrayAccess);

            SortVisualizer::changeEntitiesColor(entities[j], entities[j+1], sf::Color::Red);
            if(entities[j].getEntityHeight() > entities[j+1].getEntityHeight()) {
                visualizer.updateCounters(++comparisions, arrayAccess);
                visualizer.swapEntities(entities, j, j+1);
            }
            SortVisualizer::changeEntitiesColor(entities[j], entities[j+1], sf::Color::Cyan);
        }
    }
}
