#pragma once
#include <SFML/Graphics.hpp>
class UI
{
public:
	static void AddText(std::string text, sf::Vector2f position, int size, sf::Color color);
	static void LoadFont();
	static void RenderAllText(sf::RenderWindow* window);

private:
	static sf::Font font;
	static std::vector<sf::Text> texts;
};

