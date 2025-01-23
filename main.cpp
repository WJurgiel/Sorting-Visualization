#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "CONFIG.h"
int main()
{
    srand(time(NULL));
    sf::RenderWindow window (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting");
    std::vector<Entity> entities;
    float posX = 0;
    for(int id = 0; id < NUM_ENTITIES; id++) {
        entities.emplace_back(
            static_cast<float>(rand()% static_cast<int>(WINDOW_HEIGHT) + 40),
            posX
            );
        posX += ENTITY_WIDTH + HORIZONTAL_OFFSET;
    }
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        for(const auto& entity : entities) {
            window.draw(entity);
        }

        window.display();
    }
    return 0;
}
