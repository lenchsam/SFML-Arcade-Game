#include "Enemy.h"
#include "SpriteRenderer.h"
#include "CircleCollider.h"

namespace LLGP {
	Enemy::Enemy() {
		health = AddComponent<Health>();
		spriteRenderer = AddComponent<SpriteRenderer>();
		AddComponent<CircleCollider>();
	}
	
	void Enemy::GoToTarget(GameObject* player) {
		sf::Vector2f end = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		sf::Vector2f start = GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		sf::Vector2f direction = end - start;

		direction = direction.normalized();

		direction *= m_speed;

		GetComponent<SpriteRenderer>()->GetSprite()->move(direction);
	}
}
