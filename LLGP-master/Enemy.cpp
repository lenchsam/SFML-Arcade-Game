#include "Enemy.h"
#include "SpriteRenderer.h"

namespace LLGP {
	Enemy::Enemy() {
		health = AddComponent<Health>();
		spriteRenderer = AddComponent<SpriteRenderer>();
	}
	
	void Enemy::GoToTarget(GameObject* player) {
		sf::Vector2f end = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		sf::Vector2f start = GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		sf::Vector2f direction = end - start;

		direction.normalized();

		GetComponent<SpriteRenderer>()->GetSprite()->move(direction);

		std::cout << direction.x << +" " << direction.y << std::endl;
	}
}
