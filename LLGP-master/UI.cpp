#include "UI.h"
#include <SFML/Graphics.hpp>

sf::Font UI::font;
std::vector<sf::Text> UI::texts;

void UI::LoadFont() {
    if (!font.openFromFile("assets/CutePixel.ttf")) {
        // Handle error
    }
}

void UI::ClearText() {
    texts.clear();
}
void UI::AddText(std::string text, sf::Vector2f position, int size, sf::Color color) {
    sf::Text textObj(font);
    textObj.setString(text);
    textObj.setOrigin({ textObj.getLocalBounds().size.x / 2.0f, textObj.getLocalBounds().size.x / 2.0f });
    textObj.setCharacterSize(size);
    textObj.setFillColor(color);
    textObj.setPosition(position);

    texts.push_back(textObj);
}
sf::Text* UI::AddTextRef(std::string text, sf::Vector2f position, int size, sf::Color color) {
    sf::Text textObj(font);
    textObj.setString(text);
    textObj.setOrigin({ textObj.getLocalBounds().size.x / 2.0f, textObj.getLocalBounds().size.x / 2.0f });
    textObj.setCharacterSize(size);
    textObj.setFillColor(color);
    textObj.setPosition(position);

    texts.push_back(textObj);
    return &textObj;
}
void UI::UpdateText(sf::Text* textToUpdate, std::string newText) {
    if (textToUpdate != nullptr) {

        //textToUpdate->setString(newText);
    }
}
void UI::RenderAllText(sf::RenderWindow* window) {
    for (const auto& text : texts) {
        window->draw(text);
    }
}
