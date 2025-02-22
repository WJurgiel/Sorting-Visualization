#include <App.h>
#include <iostream>
#include <memory>
#include <SortVisualizer.h>
#include <TextLog.h>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "ProjectConfig.h"
void bubbleSort(SortVisualizer visualizer, std::vector<Entity>& entities, int n) {
    int comparisions = 0;
    int arrayAccess = 0;

    for (int i = 0; i < n-1; i++) {

        for (int j = 0; j < n-i-1; j++) {
            visualizer.updateCounters(comparisions, ++arrayAccess);

            SortVisualizer::changeEntitiesColor(entities[j], entities[j+1], sf::Color::Red);
            if(entities[j].getEntityHeight() > entities[j+1].getEntityHeight()) {
                visualizer.updateCounters(++comparisions, arrayAccess);
                visualizer.swapEntities(entities, j);
            }
            SortVisualizer::changeEntitiesColor(entities[j], entities[j+1], sf::Color::Cyan);
        }
    }
}
int main()
{
    srand(time(nullptr));
    std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    std::vector<Entity> entities;
    App* app = App::getInstance(&entities);
    sf::RenderWindow& window = app->getWindow();
    SortVisualizer sortVisualizer(*app);

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

    bubbleSort(sortVisualizer,entities, NUM_ENTITIES);

    while(window.isOpen()) {
        app->HandleEvents();
        app->Draw();
    }

    delete app;
    SoundManager::destroyInstance();
    return 0;
}
