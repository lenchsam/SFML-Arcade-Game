#include "Physics.h"
namespace LLGP {
	Event<> E_StepPhysics;

	void Physics::GetCollisionInfo() {

	}
	void Physics::DispatchCollisions() {

	}
	void Physics::AddCollider(Collider* col) {
		_Colliders.push_back(col);
		//std::cout << "added collider" << std::endl;
	}
	void Physics::CircleCollision(CircleCollider* a, CircleCollider* b) {

	}
}
