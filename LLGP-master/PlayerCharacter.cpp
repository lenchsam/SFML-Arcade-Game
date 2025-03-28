#include "PlayerCharacter.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
namespace LLGP {
	PlayerCharacter::PlayerCharacter(GameObject* owner) {
		_speed = 1.20f;
		_GameObject = owner;
	}

	void PlayerCharacter::Input(SpriteRenderer* spriteRenderer) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			_GameObject->transform->ChangePosition({ 0, -1 }, spriteRenderer);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			_GameObject->transform->ChangePosition({-1, 0}, spriteRenderer);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			_GameObject->transform->ChangePosition({ 0, 1 }, spriteRenderer);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			_GameObject->transform->ChangePosition({ 1, 0 }, spriteRenderer);
		}
	}
}
