#include <App.h>
#include <iostream>
#include <memory>
#include <TextLog.h>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "CONFIG.h"
void bubbleSort(App& app, std::vector<Entity>& entities, int n) {
    int comparisions = 0;
    TextLog& comparisionCounter = app.getComparisionsCounter();

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(entities[j].getEntityHeight() > entities[j+1].getEntityHeight()) {
                comparisions++;
                comparisionCounter.updateText("Comparisons: " + std::to_string(comparisions));
                std::swap(entities[j], entities[j+1]);

                float tempX = entities[j].getPosX();
                entities[j].setPosX(entities[j+1].getPosX());
                entities[j+1].setPosX(tempX);

                entities[j].updateColumn();
                entities[j+1].updateColumn();

                app.Draw();
                app.HandleEvents();

                sf::sleep(sf::milliseconds(1));
            }
        }
    }
}
int main()
{
    srand(time(nullptr));

    std::vector<Entity> entities;
    App* app = App::getInstance(&entities);
    sf::RenderWindow& window = app->getWindow();


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

    bubbleSort(*app,entities, NUM_ENTITIES);

    while(window.isOpen()) {
        app->HandleEvents();

    }

    delete app;
    return 0;
}
