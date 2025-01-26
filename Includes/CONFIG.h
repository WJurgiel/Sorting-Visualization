//
// Created by Wojtek on 23.01.2025.
//

#ifndef CONFIG_H
#define CONFIG_H

constexpr const char* FONT_NAME = "../Fonts/arial.ttf";
constexpr int TEXT_SIZE = 24;
constexpr float TEXT_OFFSET_Y = 24;

constexpr float HORIZONTAL_OFFSET = 1;
constexpr float VERTICAL_OFFSET = 40;
constexpr float WINDOW_WIDTH = 1600;
constexpr float WINDOW_HEIGHT = 900;
constexpr int NUM_ENTITIES = 125;
constexpr float ENTITY_WIDTH = WINDOW_WIDTH / NUM_ENTITIES - HORIZONTAL_OFFSET;

constexpr float ALGORITHM_DELAY_MS = 0.5;
#endif //CONFIG_H
