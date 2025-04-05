#include "WarriorDrone.h"
namespace LLGP {
	WarriorDrone::WarriorDrone() {
		
	}
	WarriorDrone::~WarriorDrone() {

	}

	void WarriorDrone::Init() {
		GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color(128, 128, 128));
	}
}
