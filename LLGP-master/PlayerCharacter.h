#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
namespace LLGP {
	class PlayerCharacter : public Component
	{
	public:
		PlayerCharacter(GameObject* owner);
		PlayerCharacter(const PlayerCharacter&) = default;

		void Input(SpriteRenderer* spriteRenderer);
	private:
		float _speed;
		GameObject* _GameObject;
	};
}

