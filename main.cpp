#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "CONFIG.h"
void bubbleSort(std::vector<Entity>& entities, int n) {
    entities[0].changeColor();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(entities[j].getEntityHeight() > entities[j+1].getEntityHeight()) {
                std::swap(entities[j], entities[j+1]);

                float tempX = entities[j].getPosX();
                entities[j].setPosX(entities[j+1].getPosX());
                entities[j+1].setPosX(tempX);

                entities[j].updateColumn();
                entities[j+1].updateColumn();
            }
        }
    }
}
int main()
{
    srand(time(NULL));
    sf::RenderWindow window (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting");
    std::vector<Entity> entities;
    float posX = 0;
    int randomHeights[NUM_ENTITIES];

    for(int id = 0; id < NUM_ENTITIES; id++) {
        randomHeights[id] = (rand()% static_cast<int>(WINDOW_HEIGHT) + 40 - VERTICAL_OFFSET) ;
        entities.emplace_back(
            id,
            static_cast<float>(randomHeights[id]),
            posX
            );
        posX += ENTITY_WIDTH + HORIZONTAL_OFFSET;
    }
    std::cout << "before sort: \n";
    for(auto& entity : entities) {
        std::cout << entity;
    }
    bubbleSort(entities, NUM_ENTITIES);
    std::cout << "after sort: \n";
    for(auto& entity : entities) {
        std::cout << entity;
    }
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        for(auto& entity : entities) {
            window.draw(entity);
        }

        window.display();
    }
    return 0;
}
