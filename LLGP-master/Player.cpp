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
	void Player::Shoot(float deltaTime) {
		m_time += deltaTime;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (m_time >= m_shootingSpeed) {
				Bullet* bullet = new Bullet();
				bullet->Fire(this);

				bullets.push_back(bullet);

				m_time = 0.f;
			}
		}
	}
	void Player::DrawAllBullets(sf::RenderWindow* window) {
		for (auto bullet : bullets) {
			bullet->GetComponent<SpriteRenderer>()->Draw(window);
		}
	}
}
