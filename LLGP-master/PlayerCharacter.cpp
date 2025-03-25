#include "PlayerCharacter.h"
#include <SFML/Graphics.hpp>
namespace LLGP {
	PlayerCharacter::PlayerCharacter(GameObject* owner) {
		_speed = 0.20f;
		_GameObject = owner;
	}
	void PlayerCharacter::Input(float deltaTime) {
		//handle events
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			std::cout << "up" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			std::cout << "left" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			std::cout << "down" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			std::cout << "right" << std::endl;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			std::cout << "mouseleft" << std::endl;
		}
	}
}
