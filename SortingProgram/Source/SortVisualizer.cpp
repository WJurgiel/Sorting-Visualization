//
// Created by Wojtek on 26.01.2025.
//

#include "SortVisualizer.h"

SortVisualizer::SortVisualizer(App &app) : app(app) {
    soundManager = SoundManager::getInstance();
    soundManager->addListener(this);
    soundManager->initSounds();
}

SortVisualizer::~SortVisualizer() {
    soundManager->removeListener(this);
}

void SortVisualizer::updateCounters(const int& comparisions, const int& arrayAccesses) const {
    app.getComparisionsCounter().updateText("Comparisons: " + std::to_string(comparisions));
    app.getArrayAccessCounter().updateText("Array accesses: " + std::to_string(arrayAccesses));
}

void SortVisualizer::swapEntities(std::vector<Entity> &entities, const int id1, const int id2) const {
    app.Draw();
    sf::sleep(sf::milliseconds(1));

    changeEntitiesColor(entities[id1], entities[id2], sf::Color::Green);
    app.Draw();
    sf::sleep(sf::milliseconds(1));
    std::swap(entities[id1], entities[id2]);
    float tempX = entities[id1].getPosX();
    entities[id1].setPosX(entities[id2].getPosX());
    entities[id2].setPosX(tempX);

    entities[id1].updateColumn();
    entities[id2].updateColumn();

    float value = entities[id1].getEntityHeight();
    float maxValue = WINDOW_HEIGHT;
    soundManager->playSound("beep", value, maxValue);
    app.HandleEvents();
    app.Draw();

    sf::sleep(sf::milliseconds(ALGORITHM_DELAY_MS));
}

void SortVisualizer::changeEntitiesColor(Entity &first, Entity &second, sf::Color color) {
    first.changeColor(color);
    second.changeColor(color);
}

void SortVisualizer::onPlaySound(const std::string &soundID) {
    // std::cout << "beep\n";
}
