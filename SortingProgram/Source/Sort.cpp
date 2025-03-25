//
// Created by Wojtek on 24.02.2025.
//

#include "Sort.h"

Sort::Sort(SortVisualizer &visualizer, std::vector<Entity> &entities) : visualizer(visualizer), entities(entities) {
    comparisionsCount = 0;
    arrayAccessesCount = 0;
}
