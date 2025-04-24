#include "WorkerDrone.h"
#include "Spawner.h"
#include "Scoring.h"
#include <iostream>

namespace LLGP {
	WorkerDrone::WorkerDrone() {
		m_speed = 5.f;
	}
	void WorkerDrone::Init() {
		GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color::Blue);
	}
	void WorkerDrone::DestroyThis(Spawner* spawner) {
		std::cout << "Worker Drone is destroyed" << std::endl;
		spawner->DestroyWorkerDroneFromList(this);

		Scoring::OnDeath(WORKER);

		SetActive(false);
	}

	void WorkerDrone::GoToTarget(GameObject* player) {

		//TODO:: Change this to be going towards crystals, then to sinstar boss. repeat
		//get euclidian distance between two points
		//if distance between drone and player is set distance
		//if true stop
		//if false, move towards player.
		sf::Vector2f end = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		sf::Vector2f start = GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		sf::Vector2f dist = { start.x - end.x, start.y - end.y };

		float distSquared = (dist.x * dist.x) + (dist.y * dist.y);
		float distance = sqrt(distSquared);

		if (distance <= minDistnaceFromPlayer) {
			//enemy is the min distance from the player, will not move closer
			//TODO: move in circle around the player
		}
		else {
			sf::Vector2f direction = end - start;

			direction = direction.normalized();

			direction *= m_speed;

			GetComponent<SpriteRenderer>()->GetSprite()->move(direction);
		}
	}

}
