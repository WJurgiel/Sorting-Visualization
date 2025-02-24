//
// Created by Wojtek on 24.02.2025.
//

#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "Sort.h"


class BubbleSort : public Sort{
public:
    BubbleSort(SortVisualizer& visualizer, std::vector<Entity>& entities);
    void sort() override;
    ~BubbleSort() override = default;
};

#endif //BUBBLESORT_H
