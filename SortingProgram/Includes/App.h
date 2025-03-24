//
// Created by Wojtek on 25.01.2025.
//

#ifndef APP_H
#define APP_H

#include <Entity.h>
#include <TextLog.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "IEvents.h"
#include "IUpdateBuffer.h"

class App final : public IEvents, public IUpdateBuffer {
private:
    sf::RenderWindow* window;
    std::vector<Entity>* drawableEntities;
    TextLog* algorithmNameText;
    TextLog* comparisionsCounterText;
    TextLog* arrayAccessText;
    TextLog* currentDelayText;
    TextLog* currentTimeText;
    std::string currentAlgorithmName;
    int algorithmType;

    void setAlgorithmName();
protected:
    App();

    App(std::vector<Entity> *entities, char** argv);

    explicit App(std::vector<Entity>* entities);
    static App* _instance;
public:
    ~App() override = default;
    App(App& other) = delete;
    void operator=(const App& other) = delete;

    static App *getInstance();
    static App *getInstance(std::vector<Entity>* entities, char** argv);

    static void destroyInstance();

    [[nodiscard]] sf::RenderWindow& getWindow()const;
    [[nodiscard]] TextLog& getComparisionsCounter()const;
    [[nodiscard]] TextLog& getArrayAccessCounter()const;

    void setEntityVector(std::vector<Entity>* newEntities);
    void setAlgorithmType(char** argv);
    int getAlgorithmType() const;
    void HandleEvents() override;
    void Draw() override;
};
inline App* App::_instance = nullptr;




#endif //APP_H
