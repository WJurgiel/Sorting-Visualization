//
// Created by Wojtek on 24.03.2025.
//

#include <App.h>
#include <Entity.h>
#include <gtest/gtest.h>

#include "AlgorithmType.h"
TEST(AppEssentials, IsInitializing) {
    char* argv[] = { nullptr, nullptr };
    std::vector<Entity> testEntities;
    App* app = App::getInstance(&testEntities, argv);
    ASSERT_NE(app, nullptr);

    App::destroyInstance();
}
TEST(AppEssentials, CorrectArgumentPassed) {
    char* argv[] = { (char*)"app", (char*)"1" };
    std::vector<Entity> testEntities;
    App* app = App::getInstance(&testEntities, argv);
    ASSERT_EQ(INSERTION_SORT, app->getAlgorithmType());

    App::destroyInstance();
}
TEST(AppEssentials, CorrectSortName) {
    char* argv[] = { (char*)"app", (char*)"0" };
    std::vector<Entity> testEntities;
    App* app = App::getInstance(&testEntities, argv);
    TextLog algorithmNameTextLog = app->getAlgorithmNameTextLog();
    ASSERT_EQ(algorithmNameTextLog.getMessage(), "alg_name: Bubble Sort");

    App::destroyInstance();
}