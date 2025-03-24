#include "Transform.h"

namespace LLGP {
	Transform::Transform(GameObject* owner) {
		_GameObject = owner;
	}
	sf::Vector2f Transform::GetPosition() {
		return m_Position;
	}
}
