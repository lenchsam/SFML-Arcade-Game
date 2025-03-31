#include "Player.h"
#include "Bullet.h"

namespace LLGP {
	Player::Player() {

	}
	Player::~Player() {
		delete view;
	}
	void Player::MoveCamera(sf::Vector2f movement) {
		view->move(movement);
	}
	void Player::Shoot(float* deltaTime) {
		m_Time += *deltaTime * 100;
		//std::cout << m_Time << std::endl;

		if (m_Time > m_shootingSpeed) {
			//std::cout << "shooting" << std::endl;

			Bullet* bullet = new Bullet();
			bullet->Fire(this);

			bullets.push_back(bullet);

			m_Time = 0.f;
		}
	}
	void Player::DrawAllBullets(sf::RenderWindow* window) {
		for (auto bullet : bullets) {
			bullet->GetComponent<SpriteRenderer>()->Draw(window);
		}
	}
}
