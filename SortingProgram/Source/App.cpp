//
// Created by Wojtek on 25.01.2025.
//

#include "App.h"

#include <SoundManager.h>

#include "AlgorithmType.h"

App::App() {
    window = new sf::RenderWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Sorting");
    drawableEntities = nullptr;
    std::cout << "[INFO]: In order to work on entities please assign them first with < App.setEntityVector(std::vector<Entity>*) >";
}
App::App(std::vector<Entity>* entities, char** argv) {
    window = new sf::RenderWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Sorting");
    this->drawableEntities = entities;

    this->setAlgorithmType(argv);

    this->algorithmNameText = new TextLog("alg_name: " + currentAlgorithmName);
    this->comparisionsCounterText = new TextLog("Comparisions: 0",{0, TEXT_OFFSET_Y});
    this->arrayAccessText = new TextLog("Array access: 0",{0, 2 * TEXT_OFFSET_Y});
    this->currentDelayText = new TextLog("Delay: " + std::to_string(ALGORITHM_DELAY_MS) + "ms",{0, 3 * TEXT_OFFSET_Y});

}
App* App::getInstance() {
    if (_instance == nullptr) {
        _instance = new App();
    }
    return _instance;
}
App* App::getInstance(std::vector<Entity>* entities, char** argv) {
    if (_instance == nullptr) {
        _instance = new App(entities, argv);
    }
    return _instance;
}
void App::destroyInstance() {
    delete _instance;
    _instance = nullptr;
}
sf::RenderWindow& App::getWindow() const {
    return *window;
}

TextLog & App::getComparisionsCounter() const {
    return *comparisionsCounterText;
}

TextLog & App::getArrayAccessCounter() const {
    return *arrayAccessText;
}
TextLog & App::getAlgorithmNameTextLog() const {
    return *algorithmNameText;
}
void App::setEntityVector(std::vector<Entity>* newEntities) {
    this->drawableEntities = newEntities;
}

void App::setAlgorithmType(char **argv) {
    algorithmType = (argv[1] != nullptr) ? atoi(argv[1]) : BUBBLE_SORT;

    setAlgorithmName();
}

int App::getAlgorithmType() const {
    return algorithmType;
}

const std::string & App::getAlgorithmName() const {
    return currentAlgorithmName;
}

void App::setAlgorithmName() {
    std::string m_name;
    switch(algorithmType) {
        case BUBBLE_SORT: m_name = "Bubble Sort"; break;
        case INSERTION_SORT: m_name = "Insertion Sort"; break;
        case SELECTION_SORT: m_name = "Selection Sort"; break;
        case QUICK_SORT: m_name = "Quick Sort"; break;
        default: m_name = "Unknown"; break;
    }
    currentAlgorithmName = m_name;

}

void App::HandleEvents() {
    while(const std::optional event  = window->pollEvent()) {
        if(event->is<sf::Event::Closed>()) {
            window->close();
            destroyInstance();
            SoundManager::destroyInstance();
            exit(0);
        }
        if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
           if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
               std::cout << "Esc key pressed" << std::endl;
               window->close();
               destroyInstance();
               SoundManager::destroyInstance();
               exit(0);
           }
            if(keyPressed->scancode == sf::Keyboard::Scancode::Left) {
                if(ALGORITHM_DELAY_MS > 10)
                    ALGORITHM_DELAY_MS -= 5;
                else if (ALGORITHM_DELAY_MS > 1 && ALGORITHM_DELAY_MS <= 10)
                    ALGORITHM_DELAY_MS -= 1;
                else ALGORITHM_DELAY_MS -= 0.1;

                if(ALGORITHM_DELAY_MS < 0.1)
                    ALGORITHM_DELAY_MS = 0.1;
                currentDelayText->updateText("Delay: " + std::to_string(ALGORITHM_DELAY_MS) + "ms");
            }
            if(keyPressed->scancode == sf::Keyboard::Scancode::Right) {
                if(ALGORITHM_DELAY_MS < 1)
                    ALGORITHM_DELAY_MS += 0.1;
                else if (ALGORITHM_DELAY_MS >= 0.1 && ALGORITHM_DELAY_MS < 10)
                    ALGORITHM_DELAY_MS += 1;
                else if (ALGORITHM_DELAY_MS >= 10 && ALGORITHM_DELAY_MS < 100)
                    ALGORITHM_DELAY_MS += 5;
                if(ALGORITHM_DELAY_MS >  100)
                    ALGORITHM_DELAY_MS = 100;
                currentDelayText->updateText("Delay: " + std::to_string(ALGORITHM_DELAY_MS) + "ms");
            }
        }
    }
}
void App::Draw() {
    window->clear(sf::Color::Black);
    for(const auto& entity : *drawableEntities) {
        window->draw(entity);
    }
    window->draw(*algorithmNameText);
    window->draw(*comparisionsCounterText);
    window->draw(*arrayAccessText);
    window->draw(*currentDelayText);
    window->display();
}