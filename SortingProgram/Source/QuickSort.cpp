//
// Created by Wojtek on 25.02.2025.
//

#include "QuickSort.h"

int QuickSort::partition(std::vector<Entity> &entities, int low, int high) {
    float pivot = entities[high].getEntityHeight();
    arrayAccessesCount++;
    int i = low - 1;
    for(int j = low; j < high; j++) {
        arrayAccessesCount++;
        comparisionsCount++;
        if(entities[j].getEntityHeight() <= pivot) {
            i++;
            visualizer.swapEntities(entities, i, j);
            arrayAccessesCount += 3;
            SortVisualizer::changeEntitiesColor(entities[i], entities[j], sf::Color::Cyan);
        }
        visualizer.updateCounters(comparisionsCount,arrayAccessesCount);
    }
    visualizer.swapEntities(entities, i+1, high);
    arrayAccessesCount += 3;
    visualizer.updateCounters(comparisionsCount,arrayAccessesCount);
    SortVisualizer::changeEntitiesColor(entities[i+1], entities[high], sf::Color::Cyan);
    return i+1;
}

QuickSort::QuickSort(SortVisualizer &visualizer, std::vector<Entity> &entities) : Sort(visualizer, entities){
}

void QuickSort::recursiveSort(const int low, const int high) {
    if(low < high) {
        int pivotId = partition(entities, low, high);
        recursiveSort(low, pivotId -1);
        recursiveSort(pivotId +1, high);
    }
}

void QuickSort::sort() {
    recursiveSort();
}

