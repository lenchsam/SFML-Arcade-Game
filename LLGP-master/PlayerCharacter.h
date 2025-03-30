#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
#include "Player.h"
namespace LLGP {
	class PlayerCharacter : public Component
	{
	public:
		PlayerCharacter(GameObject* owner);
		PlayerCharacter(const PlayerCharacter&) = default;

		void Input(Player* player, float* deltaTime);
	private:
		float _speed;
		GameObject* _GameObject;
	};
}

