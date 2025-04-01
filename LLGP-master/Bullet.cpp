#include "Bullet.h"
namespace LLGP {
	Bullet::Bullet() {
		transform = AddComponent<Transform>();
		spriteRenderer = AddComponent<SpriteRenderer>();
		spriteRenderer->LoadTexture("assets/sprites/BULLET.png");
		spriteRenderer->GetSprite()->setScale({2.f, 2.f});
	}
	void Bullet::Fire(GameObject* player) {
		sf::Vector2f playerPosition = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		spriteRenderer->GetSprite()->setPosition(playerPosition);

		spriteRenderer->GetSprite()->setRotation(player->GetComponent<SpriteRenderer>()->GetSprite()->getRotation());


		
	}
	void Bullet::SetPlayer(Player* player) {
		m_player = player;
	}
}
