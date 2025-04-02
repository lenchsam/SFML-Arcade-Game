#pragma once
#include <vector>
#include "Event.h"

namespace LLGP {
	class Collider;
	class CircleCollider;
	class BoxCollider;

	class Physics
	{
	public:
		Physics(){}
		//static because this isnt going to be a gameobject, allows it to be called in main
		static void GetCollisionInfo();
		static void DispatchCollisions();
		static void AddCollider(Collider* c);

		static inline Event<> E_StepPhysics;

		void CircleCollision(CircleCollider* a, CircleCollider* b);

	private:
		static inline std::vector<Collider*> _Colliders;
	};
}

