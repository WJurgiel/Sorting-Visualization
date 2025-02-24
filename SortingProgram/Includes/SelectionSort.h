//
// Created by Wojtek on 24.02.2025.
//

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Sort.h"

class SelectionSort : public Sort{
public:
    SelectionSort(SortVisualizer& visualizer, std::vector<Entity>& entities);
    void sort() override;
    ~SelectionSort() override = default;
};



#endif //SELECTIONSORT_H
