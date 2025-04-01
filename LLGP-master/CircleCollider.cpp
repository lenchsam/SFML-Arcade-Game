#include "CircleCollider.h"

namespace LLGP {
	CircleCollider::CircleCollider(GameObject* owner){
		_GameObject = owner;
		m_Radius = 1;
	}
	CircleCollider::~CircleCollider() {
		delete _GameObject;
	}
}