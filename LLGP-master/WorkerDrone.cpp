#include "WorkerDrone.h"
namespace LLGP {
	WorkerDrone::WorkerDrone() {
		
	}
	WorkerDrone::~WorkerDrone() {

	}

	void WorkerDrone::Init() {
		GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color(128, 128, 128));
	}
}
