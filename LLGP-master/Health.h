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
		void Init(float maxHealth, int numOfLives);

		bool isDestroyed = false;

		static inline LLGP::Event<GameObject*> OnEnemyDeath;
	private:
		float m_maxHealth;
		float m_health;
		GameObject* _GameObject;
		int m_numOfLives = 0;
	};
}


