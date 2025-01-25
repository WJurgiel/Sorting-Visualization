#include <App.h>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "CONFIG.h"
void bubbleSort(sf::RenderWindow& window, std::vector<Entity>& entities, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(entities[j].getEntityHeight() > entities[j+1].getEntityHeight()) {
                std::swap(entities[j], entities[j+1]);

                float tempX = entities[j].getPosX();
                entities[j].setPosX(entities[j+1].getPosX());
                entities[j+1].setPosX(tempX);

                entities[j].updateColumn();
                entities[j+1].updateColumn();

                window.clear(sf::Color::Black);
                for(const auto& entity : entities) {
                    window.draw(entity);
                }
                window.display();

                sf::Event event;
                while(window.pollEvent(event)) {
                    if(event.type == sf::Event::Closed) {
                        window.close();
                    }
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                }

                sf::sleep(sf::milliseconds(1));

            }
        }
    }
}
int main()
{
    srand(time(NULL));
    App* app = App::getInstance();
    sf::RenderWindow& window = app->getWindow();

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



    bubbleSort(window,entities, NUM_ENTITIES);

    while(window.isOpen()) {
        app->HandleEvents();
    }
    return 0;
}
