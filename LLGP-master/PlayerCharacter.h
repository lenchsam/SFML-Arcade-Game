#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
namespace LLGP {
	class PlayerCharacter : public Component
	{
	public:
		PlayerCharacter(GameObject* owner);
		PlayerCharacter(const PlayerCharacter&) = default;

		void MoveUp(float deltaTime);
		void MoveDown(float deltaTime);
		void MoveLeft(float deltaTime);
		void MoveRight(float deltaTime);
	private:
		float _speed;
		GameObject* _GameObject;
	};
}

