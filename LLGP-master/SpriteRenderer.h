#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

namespace LLGP {
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer(GameObject* owner);
		virtual ~SpriteRenderer();
		
		void LoadTexture(std::string filename);
		void SetSprite(sf::Sprite* sprite);
		sf::Sprite* GetSprite();
		void Draw(sf::RenderWindow* window);

	private:
		sf::Texture m_texture;
		sf::Sprite* m_sprite = nullptr;
		GameObject* _GameObject;
	};
}


