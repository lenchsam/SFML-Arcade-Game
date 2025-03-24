#include "PlayerCharacter.h"
namespace LLGP {
	PlayerCharacter::PlayerCharacter(GameObject* owner) {
		_speed = 0.20f;
		_GameObject = owner;
	}
	void PlayerCharacter::Tick(float deltaTime) {
		//handle events
	}
}
