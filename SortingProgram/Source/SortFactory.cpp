//
// Created by Wojtek on 24.03.2025.
//

#include "SortFactory.h"

#include <InsertionSort.h>
#include <QuickSort.h>
#include <SelectionSort.h>

#include "BubbleSort.h"

SortFactory::SortFactory(SortVisualizer &visualizer, std::vector<Entity> &entities) : sortVisualizer(visualizer), entities(entities) {
}

Sort * SortFactory::createSort(const int sortId) const {
    switch(sortId) {
        case BUBBLE_SORT: return new BubbleSort(sortVisualizer, entities);
        case INSERTION_SORT: return new InsertionSort(sortVisualizer, entities);
        case SELECTION_SORT: return new SelectionSort(sortVisualizer, entities);
        case QUICK_SORT: return new QuickSort(sortVisualizer, entities);
        default: return new BubbleSort(sortVisualizer, entities);
    }
}
