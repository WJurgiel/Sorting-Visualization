//
// Created by Wojtek on 25.01.2025.
//

#include "TextLog.h"

#include <ProjectConfig.h>
#include <iostream>
#include <ostream>
#include <SFML/Graphics/RenderTarget.hpp>

bool TextLog::loadFont() {
    char currentPath[MAX_PATH];
    GetModuleFileNameA(NULL, currentPath, MAX_PATH);

    std::string fullPath = std::filesystem::path(currentPath).parent_path().parent_path().parent_path().string() + "/" + FONT_NAME;
    std::cout << fullPath << std::endl;
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
