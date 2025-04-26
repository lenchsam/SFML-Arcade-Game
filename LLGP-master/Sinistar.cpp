#include "Sinistar.h"

namespace LLGP {
	Sinistar::Sinistar() {
		m_minDistnaceFromPlayer = 0;
	}
	Sinistar::~Sinistar() {

	}
	void Sinistar::Init() {

	}
	void Sinistar::DestroyThis(Spawner* spawner) {

	}
	void Sinistar::GoToTarget(GameObject* player, sf::Vector2f target) {
		m_target = ChooseTarget(player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition());
		Enemy::GoToTarget(player, m_target);
	}
	sf::Vector2f Sinistar::ChooseTarget(sf::Vector2f playerPosition) {
		if (m_target != targetPositions.back()) { return m_target; }
		//runs if sinstar has gone through all positions

		//get set positions around player position
		//save them positions to a vector
		//current target = first element in vector
	}
}
