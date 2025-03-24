#include "SpriteRenderer.h"

namespace LLGP {
	SpriteRenderer::SpriteRenderer(GameObject* owner) : m_sprite(m_texture) {
		_GameObject = owner;
	}

	void SpriteRenderer::SetSprite(sf::Sprite sprite) {
		m_sprite = sprite;
	}

	void SpriteRenderer::LoadTexture(std::string filename) {
		if (!m_texture.loadFromFile(filename)) { 
			std::cout << "no texture found" << std::endl;
			return;
		}
		std::cout << "texture found" << std::endl;
		m_sprite.setTexture(m_texture);
		m_sprite.setScale({ 5.0f, 5.0f }); // absolute scale factor
		m_sprite.setPosition({ 200.f, 200.f }); // absolute position

	}
	sf::Sprite SpriteRenderer::GetSprite() {
		//std::cout << "returned sprite" << std::endl;
		return m_sprite;
	}
}
