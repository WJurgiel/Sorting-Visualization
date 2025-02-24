//
// Created by Wojtek on 26.01.2025.
//

#ifndef ISOUNDLISTENER_H
#define ISOUNDLISTENER_H
#include <string>


class ISoundListener {
public:
    virtual ~ISoundListener() = default;
    virtual void onPlaySound(const std::string& soundID) = 0;
};



#endif //ISOUNDLISTENER_H
