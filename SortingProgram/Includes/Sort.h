//
// Created by Wojtek on 24.02.2025.
//

#ifndef SORT_H
#define SORT_H

#include "SortVisualizer.h"
#include "Entity.h"
class Sort {
protected:
    SortVisualizer& visualizer;
    std::vector<Entity>& entities;
public:
    Sort(SortVisualizer& visualizer, std::vector<Entity>& entities);
    virtual ~Sort() = default;
    virtual void sort(){};
};



#endif //SORT_H
