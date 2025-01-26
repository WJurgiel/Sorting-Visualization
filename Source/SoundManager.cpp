// //
// // Created by Wojtek on 26.01.2025.
// //
//
#include "SoundManager.h"

#include <CONFIG.h>
#include <iostream>

SoundManager * SoundManager::getInstance() {
    if(!instance) {
        instance = new SoundManager;
    }
    return instance;
}

void SoundManager::destroyInstance() {
    delete instance;
    instance = nullptr;
}

bool SoundManager::loadSound(const std::string &name, const std::string &path) {
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile(SFX_NAME)) {
        std::cerr << "Failed to load sound buffer from " << path << std::endl;
        return false;
    }
    soundBuffers[name] = buffer;
    sounds[name].setBuffer(soundBuffers[name]);
    return true;
}

SoundManager::~SoundManager() {
    for (auto& [name, sound] : sounds) {
        sound.stop();
    }
    sounds.clear();
    soundBuffers.clear();
}

void SoundManager::initSounds() {
    loadSound("beep", SFX_NAME);
}

void SoundManager::playSound(const std::string &name, const float value, const float maxValue) {
    if(sounds.find(name) != sounds.end()) {
        auto now = std::chrono::steady_clock::now();
        int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastPlayTime).count();
        if(elapsed >= soundCooldown) {
            float pitch = 0.5f + (value/maxValue) * 1.5f;
            sounds[name].setPitch(pitch);
            sounds[name].setVolume(5.f);
            sounds[name].play();
            lastPlayTime = now;
            notifyListeners(name);
        }

    }else {
        std::cerr << "Sound: " << name << " not found" << std::endl;
    }
}

void SoundManager::addListener(ISoundListener *listener) {
    listeners.push_back(listener);
}

void SoundManager::removeListener(ISoundListener *listener) {
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

void SoundManager::notifyListeners(const std::string &soundName) {
    for(auto listener : listeners) {
        listener->onPlaySound(soundName);
    }
}
