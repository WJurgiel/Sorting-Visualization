//
// Created by Wojtek on 25.02.2025.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sort.h"


class QuickSort : public Sort {
private:
    int partition(std::vector<Entity>& entities, int low, int high);

public:
    QuickSort(SortVisualizer& visualizer, std::vector<Entity>& entities);
    void recursiveSort(int low=0, int high = NUM_ENTITIES-1);
    void sort() override;
    ~QuickSort() override = default;
};



#endif //QUICKSORT_H
