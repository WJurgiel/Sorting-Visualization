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

void SortVisualizer::swapEntities(std::vector<Entity> &entities, const int id) const {
    // app.getWindow().display();
    app.Draw();
    sf::sleep(sf::milliseconds(1));

    changeEntitiesColor(entities[id], entities[id+1], sf::Color::Green);
    app.Draw();
    sf::sleep(sf::milliseconds(1));
    std::swap(entities[id], entities[id+1]);
    float tempX = entities[id].getPosX();
    entities[id].setPosX(entities[id+1].getPosX());
    entities[id+1].setPosX(tempX);

    entities[id].updateColumn();
    entities[id+1].updateColumn();

    float value = entities[id].getEntityHeight();
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
