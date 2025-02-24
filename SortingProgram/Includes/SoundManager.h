//
// Created by Wojtek on 26.01.2025.
//

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <ISoundListener.h>
#if defined(_WIN32)
#include <windows.h>
#endif
#include <SFML/Audio.hpp>

class SoundManager {
private:
    static SoundManager* instance;

    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    std::vector<ISoundListener*> listeners;

    std::chrono::steady_clock::time_point lastPlayTime;
    int soundCooldown = 1;

    bool loadSound(const std::string& name, const std::string& filePath);

    SoundManager():sound(sf::Sound(soundBuffer)) {}

public:
    ~SoundManager();
    SoundManager(SoundManager& other) = delete;
    void operator= (const SoundManager& other) = delete;

    static SoundManager* getInstance();
    static void destroyInstance();

    void initSounds();
    void playSound(const std::string& name, float value, float maxValue);
    void addListener(ISoundListener* listener);
    void removeListener(ISoundListener* listener);
    void notifyListeners(const std::string& soundName);
};

inline SoundManager* SoundManager::instance = nullptr;

#endif //SOUNDMANAGER_H
