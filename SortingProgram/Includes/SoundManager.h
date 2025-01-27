//
// Created by Wojtek on 26.01.2025.
//

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <chrono>
#include <ISoundListener.h>
#include <map>
#include <SFML/Audio.hpp>

class SoundManager {
private:
    static SoundManager* instance;

    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Sound> sounds;
    std::vector<ISoundListener*> listeners;

    std::chrono::steady_clock::time_point lastPlayTime;
    int soundCooldown = 1;

    bool loadSound(const std::string& name, const std::string& filePath);

    SoundManager() = default;
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
