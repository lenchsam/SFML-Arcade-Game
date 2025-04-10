#include "Crystal.h"
#include "CircleCollider.h"
#include <iostream>
#include <random>
namespace LLGP {
	Crystal::Crystal(sf::Vector2f pos) {
		transform = AddComponent<Transform>();
		spriteRenderer = AddComponent<SpriteRenderer>();
		AddComponent<CircleCollider>()->SetRadius(7);
		spriteRenderer->LoadTexture("assets/sprites/EXTRA_LIFE.png");
		spriteRenderer->GetSprite()->setScale({ 2.f, 2.f });

		RandomisePosition(pos);

		//SpriteRenderer::RenderSprite += std::bind(&Crystal::Draw, this, std::placeholders::_1);
	}

	void Crystal::Draw(sf::RenderWindow* window) {
		//std::cout << "random number " << distrib(gen) << std::endl;
		spriteRenderer->Draw(window);
	}

	void Crystal::RandomisePosition(sf::Vector2f pos) {

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(-100, 100);

		//std::cout << "random number " << distrib(gen) << std::endl;
		int randomX = distrib(gen);
		int randomY = distrib(gen);

		spriteRenderer->GetSprite()->setPosition({pos.x + randomX, pos.y + randomY });
	}
}
