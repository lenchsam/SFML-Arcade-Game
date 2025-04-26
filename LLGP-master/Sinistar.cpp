#include "Sinistar.h"

namespace LLGP {
	Sinistar::Sinistar() {
		m_minDistnaceFromPlayer = 0;
		currentStarLocation = 0;
		m_target = { 0, 0 };
	}
	Sinistar::~Sinistar() {

	}
	void Sinistar::Init() {

	}
	void Sinistar::DestroyThis(Spawner* spawner) {

	}
	void Sinistar::GoToTarget(GameObject* player, sf::Vector2f /*target*/) {
		m_target = ChooseTarget(player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition());
		Enemy::GoToTarget(player, m_target);
	}
	sf::Vector2f Sinistar::ChooseTarget(sf::Vector2f playerPosition) {
		//if sinistar is not at m_target return m_target
		// else if m_target is not the last target in the positionsVector return next target
		//get new positions based off of player position
		//return first item in that array

		//TODO:: make this work. issue is most likely to do with line 31, but not confirmed
		//TODO: add multiple attack sequences for variety when fighting the boss
		
		if (spriteRenderer->GetSprite()->getPosition() != m_target) {
			std::cout << "not yet reached the target position" << std::endl;
			return m_target;
		}
		else if(m_target != targetPositions.back()){
			std::cout << "next target" << std::endl;
			currentStarLocation++;
			return targetPositions[currentStarLocation];
		}

		targetPositions.clear();
		for (sf::Vector2f point : starLocations) {
			targetPositions.push_back(playerPosition + point);
		}

		std::cout << "finished all in list" << std::endl;

		currentStarLocation = 0;
		return targetPositions[0];
	}
}
