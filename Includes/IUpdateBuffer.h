//
// Created by Wojtek on 25.01.2025.
//

#ifndef IUPDATEBUFFER_H
#define IUPDATEBUFFER_H

class IUpdateBuffer{
protected:
    virtual ~IUpdateBuffer() = default;
    virtual void Draw() = 0;
};

#endif //IUPDATEBUFFER_H
