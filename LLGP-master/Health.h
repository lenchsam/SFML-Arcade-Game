#pragma once
#include "Component.h"
namespace LLGP {
	class Health :
		public Component
	{
	public:
		Health(GameObject* _GameObject);
		float GetHealth();
		void DealDamage(float damage);
		void Die();
	private:
		float m_health;
		GameObject* _GameObject;
	};
}


