//
// Created by Wojtek on 25.01.2025.
//

#include "TextLog.h"

#include <ProjectConfig.h>
#include <iostream>
#include <ostream>
#include <SFML/Graphics/RenderTarget.hpp>

bool TextLog::loadFont() {
    if(!font.openFromFile(FONT_NAME)) {
        std::cerr << "Failed to load font file " << FONT_NAME << std::endl;
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
