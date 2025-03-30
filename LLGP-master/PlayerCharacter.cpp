#include "PlayerCharacter.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
namespace LLGP {
	PlayerCharacter::PlayerCharacter(GameObject* owner) {
		_speed = 1.20f;
		_GameObject = owner;
		_GameObject->SetTag("Player");
	}

	void PlayerCharacter::Input(Player* player, float* deltaTime) {
		SpriteRenderer* spriteRenderer = player->GetComponent<SpriteRenderer>();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			_GameObject->transform->ChangePosition({ 0, -1 }, spriteRenderer);
			player->MoveCamera({ 0, -1 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			_GameObject->transform->ChangePosition({-1, 0}, spriteRenderer);
			player->MoveCamera({ -1, 0 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			_GameObject->transform->ChangePosition({ 0, 1 }, spriteRenderer);
			player->MoveCamera({ 0, 1 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			_GameObject->transform->ChangePosition({ 1, 0 }, spriteRenderer);
			player->MoveCamera({ 1, 0 });
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			player->Shoot(deltaTime);
		}
	}
}
