//
// Created by Wojtek on 25.01.2025.
//

#include "TextLog.h"

#include <ProjectConfig.h>
#include <iostream>
#include <ostream>
#include <SFML/Graphics/RenderTarget.hpp>

bool TextLog::loadFont() {
#if defined (_WIN32)
    char currentPath[MAX_PATH];
    GetModuleFileNameA(NULL, currentPath, MAX_PATH);

    std::string fullPath = std::filesystem::path(currentPath).parent_path().parent_path().parent_path().string() + "/" + FONT_NAME;
    std::cout << fullPath << std::endl;
#elif __linux__
    char currentPath[1024]; 
    ssize_t count = readlink("/proc/self/exe", currentPath, sizeof(currentPath) - 1);
    std::string fullPath;
    if (count != -1) {
        currentPath[count] = '\0'; 
        fullPath = std::filesystem::path(currentPath).parent_path().parent_path().parent_path().string() + "/" + FONT_NAME;
    }
    else{
        fullPath = "";
    }
#endif
    if(!font.openFromFile(fullPath)) {
        std::cerr << "Failed to load font file " << fullPath << std::endl;
        return false;
    }
    return true;
}

TextLog::TextLog(const std::string &startString, sf::Vector2f pos) : text(sf::Text(font, "")) {
    if(!loadFont()) return;

    text.setFont(font);
    text.setCharacterSize(TEXT_SIZE);
    text.setString(startString);
    text.setFillColor(sf::Color::Green);
    text.setPosition(pos);
}

void TextLog::updateText(std::string newString) {
    text.setString(newString);
}

void TextLog::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text, states);
}

std::string TextLog::getMessage() const {
    return text.getString();
}
