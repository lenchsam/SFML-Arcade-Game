#include "Bullet.h"
namespace LLGP {
	Bullet::Bullet() {
		spriteRenderer = AddComponent<SpriteRenderer>();
		spriteRenderer->LoadTexture("assets/sprites/BULLET.png");
		spriteRenderer->GetSprite()->setScale({2.f, 2.f});
		Fire();
	}
	void Bullet::Fire() {
		//sf::Vector2f targetPosition = m_player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		//spriteRenderer->GetSprite()->move();
	}
	void Bullet::SetPlayer(Player* player) {
		m_player = player;
	}
}
