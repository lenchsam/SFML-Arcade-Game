#pragma once
#include "GameObject.h"
namespace LLGP {
	class SpriteRenderer;
	class Crystal : public GameObject
	{
	public:
		Crystal(sf::Vector2f pos);
		~Crystal();

		void RandomisePosition(sf::Vector2f pos);
		SpriteRenderer* spriteRenderer;
	private:
		void Draw(sf::RenderWindow* window);
	};
}

