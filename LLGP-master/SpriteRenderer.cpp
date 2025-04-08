#include "SpriteRenderer.h"

namespace LLGP {
	SpriteRenderer::SpriteRenderer(GameObject* owner)
	{
		_GameObject = owner;
	}

	SpriteRenderer::~SpriteRenderer()
	{
		delete m_sprite;
	}

	void SpriteRenderer::OwnerActiveChange(bool newActive) {
		canDraw = false;
	}

	void SpriteRenderer::SetSprite(sf::Sprite* sprite) 
	{
		m_sprite = sprite;
	}

	void SpriteRenderer::LoadTexture(std::string filename) 
	{
		if (!m_texture.loadFromFile(filename)) 
		{ 
			std::cout << "no texture found" << std::endl;
			return;
		}
		//std::cout << "texture found" << std::endl;

		m_sprite = new sf::Sprite(m_texture);
		if (m_sprite != nullptr)
		{
			//m_sprite->setTexture(m_texture);
			m_sprite->setScale({ 2.0f, 2.0f }); // absolute scale factor
			m_sprite->setPosition({ 500.f, 500.f }); // absolute position
			sf::FloatRect bounds = m_sprite->getLocalBounds();
			m_sprite->setOrigin(bounds.getCenter());
		}

	}
	sf::Sprite* SpriteRenderer::GetSprite() 
	{
		//std::cout << "returned sprite" << std::endl;
		return m_sprite;
	}
	void SpriteRenderer::Draw(sf::RenderWindow* window) 
	{
		if (m_sprite != nullptr && canDraw == true)
		{
			//std::cout << "drawing to screen" << std::endl;
			window->draw(*m_sprite);
		}
	}
}
