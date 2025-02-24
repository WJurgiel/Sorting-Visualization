//
// Created by Wojtek on 25.01.2025.
//

#ifndef IEVENTS_H
#define IEVENTS_H

class IEvents{
public:
    virtual ~IEvents() = default;
    virtual void HandleEvents() = 0;
};
#endif //IEVENTS_H
