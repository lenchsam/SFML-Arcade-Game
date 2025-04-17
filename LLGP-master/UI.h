#pragma once
#include <SFML/Graphics.hpp>
class UI
{
public:
	static void AddText(std::string text, sf::Vector2f position, int size, sf::Color color);
	static sf::Text* AddTextRef(std::string text, sf::Vector2f position, int size, sf::Color color); // called for text that would need to be updated.
	static void UpdateText(sf::Text* textToUpdate, std::string newText);
	static void LoadFont();
	static void RenderAllText(sf::RenderWindow* window);
	static void ClearText();

private:
	static sf::Font font;
	static std::vector<sf::Text> texts;
};

