#include "SpriteRenderer.h"

namespace LLGP {
	SpriteRenderer::SpriteRenderer(GameObject* owner) : m_sprite(m_texture) {
		_GameObject = owner;
	}

	void SpriteRenderer::SetSprite(sf::Sprite sprite) {
		m_sprite = sprite;
	}

	void SpriteRenderer::LoadTexture(std::string filePath) {
		if (m_texture.loadFromFile(filePath))
		{
			//m_Sprite
		}
	}
}
