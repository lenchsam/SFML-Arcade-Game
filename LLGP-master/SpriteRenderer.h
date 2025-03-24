#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

namespace LLGP {
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer(GameObject* owner);
		void LoadTexture(std::string filePath);
		void SetSprite(sf::Sprite sprite);
	private:
		sf::Texture m_texture;
		sf::Sprite m_sprite;
	};
}


