#include "Player.h"
#include "Bullet.h"
#include "CircleCollider.h"
#include "PlayerCharacter.h"
namespace LLGP {
	Player::Player(sf::View* view) {
		SpriteRenderer* playerSpriteRenderer = AddComponent<LLGP::SpriteRenderer>();
		playerSpriteRenderer->LoadTexture("assets/sprites/PLAYER.png");
		AddComponent<PlayerCharacter>();
		AddComponent<CircleCollider>();
		m_view = view;
		
	}
	Player::~Player() {
		delete m_view;
	}
	void Player::MoveCamera(sf::Vector2f movement) {
		m_view->move(movement);
	}
	void Player::Shoot(float deltaTime, sf::RenderWindow *window) {
		m_time += deltaTime;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (m_time >= m_shootingSpeed) {
				Bullet* bullet = new Bullet();
				bullet->Fire(this, window);

				_Bullets.push_back(bullet);

				m_time = 0.f;
			}
		}
	}

	void Player::DrawAllBullets(sf::RenderWindow* window) {
		for (auto bullet : _Bullets) {
			bullet->GetComponent<SpriteRenderer>()->Draw(window);
		}
	}

	void Player::MoveAllBullets() {
		for (auto bullet : _Bullets) {
			bullet->MoveBullet();
		}
	}
}
