#include "PlayerCharacter.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
namespace LLGP {
	PlayerCharacter::PlayerCharacter(GameObject* owner) {
		_speed = 10.20f;
		_GameObject = owner;
	}
	void PlayerCharacter::MoveUp(float deltaTime) {
		sf::Sprite* playerSprite = _GameObject->GetComponent<SpriteRenderer>()->GetSprite();

		_GameObject->transform->ChangePosition(sf::Vector2f(0, -_speed * deltaTime));
		playerSprite->move(_GameObject->transform->GetPosition());
	}
	void PlayerCharacter::MoveDown(float deltaTime) {
		sf::Sprite* playerSprite = _GameObject->GetComponent<SpriteRenderer>()->GetSprite();

		std::cout << "down" << std::endl;

		_GameObject->transform->ChangePosition(sf::Vector2f(0, _speed * deltaTime));
		playerSprite->move(_GameObject->transform->GetPosition());
	}
	void PlayerCharacter::MoveLeft(float deltaTime) {
		sf::Sprite* playerSprite = _GameObject->GetComponent<SpriteRenderer>()->GetSprite();

		std::cout << "left" << std::endl;

		_GameObject->transform->ChangePosition(sf::Vector2f(-_speed * deltaTime, 0.0f));
		playerSprite->move(_GameObject->transform->GetPosition());
	}
	void PlayerCharacter::MoveRight(float deltaTime) {
		sf::Sprite* playerSprite = _GameObject->GetComponent<SpriteRenderer>()->GetSprite();

		std::cout << "right" << std::endl;

		_GameObject->transform->ChangePosition(sf::Vector2f(_speed * deltaTime, 0.0f));
		playerSprite->move(_GameObject->transform->GetPosition());
	}
}
