//
// Created by Wojtek on 24.02.2025.
//

#include "SelectionSort.h"

SelectionSort::SelectionSort(SortVisualizer &visualizer, std::vector<Entity> &entities) : Sort(visualizer, entities){
}

void SelectionSort::sort() {
    int n = NUM_ENTITIES;
    for(int i = 0; i < n; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j += 1) {
            if(entities[j].getEntityHeight() < entities[minIndex].getEntityHeight()) minIndex = j;
        }
        visualizer.swapEntities(entities, i, minIndex);
        SortVisualizer::changeEntitiesColor(entities[i], entities[minIndex], sf::Color::Cyan);
    }
}
