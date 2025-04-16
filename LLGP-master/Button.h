#pragma once
#include <SFML/Graphics.hpp>
class Button
{
public:
	Button() {};
	~Button() {};
	std::string text;

	void ClickCheck();

private:
	sf::Rect<int> bounds;
};

