#include <App.h>
#include <EntityManager.h>
#include <iostream>
#include <SortFactory.h>
#include <SortVisualizer.h>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "ProjectConfig.h"
int main(int argc, char** argv)
{
    srand(time(nullptr));
    std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    EntityManager entityManager;
    entityManager.generateEntities();

    App* app = App::getInstance(&entityManager.getEntities(), argv);
    sf::RenderWindow& window = app->getWindow();
    SortVisualizer sortVisualizer(*app);

    SortFactory sortFactory(sortVisualizer, entityManager.getEntities());
    Sort* sortingAlgorithm = sortFactory.createSort(app->getAlgorithmType());
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
