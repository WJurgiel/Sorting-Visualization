//
// Created by Wojtek on 24.02.2025.
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "Sort.h"


class InsertionSort : public Sort {
public:
    InsertionSort(SortVisualizer& visualizer, std::vector<Entity>& entities);
    void sort() override;
    ~InsertionSort() override = default;
};



#endif //INSERTIONSORT_H
