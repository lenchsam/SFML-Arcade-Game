#include "UI.h"
#include <SFML/Graphics.hpp>

sf::Font UI::font;
std::vector<sf::Text> UI::texts;

void UI::LoadFont() {
    if (!font.openFromFile("assets/CutePixel.ttf")) {
        // Handle error
    }
}
void UI::AddText(std::string text, sf::Vector2f position, int size, sf::Color color) {
    sf::Text textObj(font);
    textObj.setString(text);
    textObj.setCharacterSize(size);
    textObj.setFillColor(color);
    textObj.setPosition(position);
    texts.push_back(textObj);

    //std::cout << "Displaying text: " << text << std::endl;
}
void UI::RenderAllText(sf::RenderWindow* window) {
    for (const auto& text : texts) {
        window->draw(text);
    }
}
