#include <App.h>
#include <InsertionSort.h>
#include <iostream>
#include <memory>
#include <QuickSort.h>
#include <SelectionSort.h>
#include <SortFactory.h>
#include <SortVisualizer.h>
#include <TextLog.h>
#include <SFML/Graphics.hpp>

#include "BubbleSort.h"
#include "Entity.h"
#include "ProjectConfig.h"
#include "AlgorithmType.h"
int main(int argc, char** argv)
{
    const int algorithmType = (argv[1] != nullptr) ? atoi(argv[1]) : 0;
    std::string algorithmName = std::to_string(algorithmType);
    srand(time(nullptr));
    std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    std::vector<Entity> entities;


    App* app = App::getInstance(&entities, algorithmName);
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

    SortFactory sortFactory(sortVisualizer, entities);
    Sort* sortingAlgorithm = sortFactory.createSort(algorithmType);
    sortingAlgorithm->sort();

    while(window.isOpen()) {
        app->HandleEvents();
        app->Draw();
    }

    delete app;
    delete sortingAlgorithm;
    SoundManager::destroyInstance();
    return 0;
}
