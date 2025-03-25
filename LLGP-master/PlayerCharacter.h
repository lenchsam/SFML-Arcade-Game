#pragma once
#include "Component.h"
namespace LLGP {
	class PlayerCharacter : public Component
	{
	public:
		PlayerCharacter(GameObject* owner);
		PlayerCharacter(const PlayerCharacter&) = default;

		void Input(float deltaTime);
	private:
		float _speed;
	};
}

