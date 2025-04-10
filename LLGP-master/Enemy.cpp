#include "Enemy.h"
#include "SpriteRenderer.h"
#include "CircleCollider.h"
#include "Bullet.h"
#include <numbers>

namespace LLGP {
	Enemy::Enemy() {
		health = AddComponent<Health>();
		spriteRenderer = AddComponent<SpriteRenderer>();
		circleCollider = AddComponent<CircleCollider>();

		SpriteRenderer::RenderSprite += std::bind(&Enemy::Draw, this, std::placeholders::_1);
	}
	void Enemy::Draw(sf::RenderWindow* window) {
		spriteRenderer->Draw(window);
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
			//std::cout << "other is bullet - from enemy" << std::endl;
			health->DealDamage(bullet->m_Damage);
			//bullet->Destroy();
		}
		else {
			//std::cout << "other is NOT bullet - from enemy" << std::endl;
		}
	}
	void Enemy::Init() {

	}
	void Enemy::DestroyThis(Spawner* spawner) {
		std::cout << "Enemy is destroyed" << std::endl;
	}
	void Enemy::RotateTowardsPlayer(GameObject* player) {
		sf::Vector2f playerPosition = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		sf::Vector2f spritePosition = GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		float a = spritePosition.x - playerPosition.x;
		float b = spritePosition.y - playerPosition.y;

		float rotation = (atan2(b, a)) * 180 / std::numbers::pi;

		GetComponent<SpriteRenderer>()->GetSprite()->setRotation(sf::degrees(rotation - 90));
	}
}
