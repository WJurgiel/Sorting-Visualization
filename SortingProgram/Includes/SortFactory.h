//
// Created by Wojtek on 24.03.2025.
//

#ifndef SORTFACTORY_H
#define SORTFACTORY_H
#include "Sort.h"
#include "AlgorithmType.h"

class SortFactory {
private:
    SortVisualizer& sortVisualizer;
    std::vector<Entity>& entities;
public:
    SortFactory(SortVisualizer& visualizer, std::vector<Entity>& entities);
    [[nodiscard]] Sort* createSort(int sortId) const;
};



#endif //SORTFACTORY_H
