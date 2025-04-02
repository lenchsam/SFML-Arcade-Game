#include "CircleCollider.h"
#include "GameObject.h"

namespace LLGP {

	CircleCollider::CircleCollider(GameObject* owner) : m_Radius(1.0f), _GameObject(owner) {
		Physics::AddCollider(this);
		
	};
	void CircleCollider::SetRadius(float radius) {

	}
}