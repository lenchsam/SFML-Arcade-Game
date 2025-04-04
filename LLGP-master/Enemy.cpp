#include "Enemy.h"
#include "SpriteRenderer.h"
#include "CircleCollider.h"
#include "Bullet.h"

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

	void Enemy::OnCollision(GameObject* other) {
		//if other is a bullet
		//	take damage
		//	destory bullet
		//if other is not bullet
		//stop moving

		Bullet* bullet = dynamic_cast<Bullet*>(other);

		if (bullet) {
			//if other object is a bullet
			std::cout << "other is bullet - from enemy" << std::endl;
			//TakeDamage();
			//bullet->Destroy();
		}
		else {
			std::cout << "other is NOT bullet - from enemy" << std::endl;
		}
	}
}
