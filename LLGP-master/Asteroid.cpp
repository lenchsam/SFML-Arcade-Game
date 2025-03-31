#include "Asteroid.h"
namespace LLGP {
	Asteroid::Asteroid() {

	}
	Asteroid::~Asteroid() {

	}

	void Asteroid::GoToTarget(GameObject* player) {
		sf::Vector2f end = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		sf::Vector2f start = GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		sf::Vector2f direction = end - start;

		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length != 0) {
			direction /= length;
		}

		//direction.normalized();

		GetComponent<SpriteRenderer>()->GetSprite()->move(direction * m_speed);

		//std::cout << direction.x << + " " << direction.y << std::endl;
	}
}
