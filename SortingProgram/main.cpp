#include <App.h>
#include <InsertionSort.h>
#include <iostream>
#include <memory>
#include <SelectionSort.h>
#include <SortVisualizer.h>
#include <TextLog.h>
#include <SFML/Graphics.hpp>

#include "BubbleSort.h"
#include "Entity.h"
#include "ProjectConfig.h"

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

    Sort* bubbleSort = new SelectionSort(sortVisualizer, entities);

    bubbleSort->sort();

    while(window.isOpen()) {
        app->HandleEvents();
        app->Draw();
    }

    delete app;
    delete bubbleSort;
    SoundManager::destroyInstance();
    return 0;
}
