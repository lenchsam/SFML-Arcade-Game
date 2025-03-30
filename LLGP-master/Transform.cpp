#include "Transform.h"
#include "GameObject.h"
#include <numbers>

namespace LLGP {
	Transform::Transform(GameObject* owner) {
		_GameObject = owner;
		sf::Vector2f* m_Position = new sf::Vector2f(0, 0);
	}

	//Transform::~Transform() {
	//	delete m_Position;
	//}

	sf::Vector2f Transform::GetPosition() {
		return m_Position;
	}

	void Transform::ChangePosition(sf::Vector2f distance, SpriteRenderer* spriteRenderer) {
		m_Position += distance;
		spriteRenderer->GetSprite()->move(distance);

		//std::cout << "m_Position" << std::endl;
	}
	void Transform::RotateTowards(sf::RenderWindow* window, SpriteRenderer* spriteRenderer) {
		sf::Vector2i cursorPosition = sf::Mouse::getPosition(*window);
		sf::Vector2f spritePosition = spriteRenderer->GetSprite()->getPosition();

		float a = spritePosition.x - cursorPosition.x;
		float b = spritePosition.y - cursorPosition.y;

		float rotation = (atan2(b, a)) * 180 / std::numbers::pi;

		spriteRenderer->GetSprite()->setRotation(sf::degrees(rotation - 90));
	}
}
