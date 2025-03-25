//
// Created by Wojtek on 24.03.2025.
//

#include <App.h>
#include <Entity.h>
#include <gtest/gtest.h>

#include "AlgorithmType.h"
TEST(AppEssentials, IsInitializing) {
    char** argv;
    std::vector<Entity> testEntities;
    App* app = App::getInstance(&testEntities, argv);
    ASSERT_NE(app, nullptr);

    delete app;
}
TEST(AppEssentials, CorrectArgumentPassed) {
    char** argv = new char*[2];
    argv[0] = new char[3]{'a', 'p', 'p'};

    argv[1] = new char[2]{'1', '\0'};
    std::vector<Entity> testEntities;
    App* app = App::getInstance(&testEntities, argv);
    ASSERT_EQ(BUBBLE_SORT, app->getAlgorithmType());

    delete[] argv;
    delete app;
}
TEST(AppEssentials, CorrectSortName) {
    char** argv = new char*[2];
    argv[0] = new char[3]{'a', 'p', 'p'};
    argv[1] = new char[2]{'0', '\0'};
    char** argv2 = new char*[2];
    argv2[0] = new char[3]{'a', 'p', 'p'};
    argv2[1] = new char[2]{'1', '\0'};
    std::vector<Entity> testEntities;
    App* app = App::getInstance(&testEntities, argv);
    TextLog algorithmNameTextLog = app->getAlgorithmNameTextLog();
    ASSERT_EQ(algorithmNameTextLog.getMessage(), "alg_name: Bubble Sort");

    App::destroyInstance();
    App* app2 = App::getInstance(&testEntities, argv2);
    algorithmNameTextLog = app->getAlgorithmNameTextLog();
    ASSERT_EQ(algorithmNameTextLog.getMessage(), "alg_name: Insertion Sort");

    delete[] argv;
    delete[] argv2;
    delete app;
}