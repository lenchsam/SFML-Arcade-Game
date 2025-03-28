#include "Transform.h"

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
}
