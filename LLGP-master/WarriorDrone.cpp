#include "WarriorDrone.h"
#include "Spawner.h"

namespace LLGP {
	WarriorDrone::WarriorDrone() {
		m_speed = 5.f;
		
	}
	WarriorDrone::~WarriorDrone() {

	}
	void WarriorDrone::Init() {
		GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color(128, 128, 128));
	}
	void WarriorDrone::GoToTarget(GameObject* player) {

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
	void WarriorDrone::DestroyThis(Spawner* spawner) {
		std::cout << "Worker Drone is destroyed" << std::endl;
		spawner->DestroyWarriorDroneFromList(this);
		RemoveComponent<CircleCollider>(circleCollider);
		SetActive(false);

	}
}
