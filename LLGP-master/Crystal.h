#pragma once
#include "GameObject.h"
namespace LLGP {
	class SpriteRenderer;
	class Crystal : public GameObject
	{
	public:
		Crystal();
		~Crystal();
		SpriteRenderer* spriteRenderer;


	};
}

