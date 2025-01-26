//
// Created by Wojtek on 25.01.2025.
//

#ifndef TEXTLOG_H
#define TEXTLOG_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>


class TextLog : public sf::Drawable{
    sf::Text text;
    sf::Font font;
    bool loadFont();
public:
    explicit TextLog(const std::string &startString);
    void updateText(std::string newString);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //TEXTLOG_H
