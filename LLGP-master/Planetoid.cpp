#include "Planetoid.h"
#include "CircleCollider.h"
#include "Bullet.h"
#include "Spawner.h"
#include "Crystal.h"
#include "SpriteRenderer.h"

namespace LLGP {
	Planetoid::Planetoid() {
		circleCollider->SetRadius(25.f);

		//TODO: SET RANDOM NUMBER OF CRYSTALS BETWEEN 1 AND 10

		//SpriteRenderer::RenderSprite += std::bind(&Planetoid::Drawing, this, std::placeholders::_1);
	}
	Planetoid::~Planetoid() {

	}

	//void Planetoid::Drawing(sf::RenderWindow* window) {
	//	std::cout << "drawing planetoid" << std::endl;
	//	spriteRenderer->Draw(window);
	//}

	void Planetoid::OnCollision(GameObject* other) {

		Bullet* bullet = dynamic_cast<Bullet*>(other);

		if (bullet) {
			//if other object is a bullet
			//std::cout << "other is bullet - from enemy" << std::endl;
			health->DealDamage(bullet->m_Damage);
			//bullet->Destroy();
		}
		else {
			//std::cout << "other is NOT bullet - from enemy" << std::endl;
		}
	}
	void Planetoid::RandomMovements() {

	}
	void Planetoid::Init() {

	}
	void Planetoid::GoToTarget(GameObject* player){
		sf::Vector2f end = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		sf::Vector2f start = GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		sf::Vector2f direction = end - start;

		direction = direction.normalized();

		direction *= m_speed;

		GetComponent<SpriteRenderer>()->GetSprite()->move(direction);
	}
	void Planetoid::DestroyThis(Spawner* spawner) {
		std::cout << "Planetoid is destroyed" << std::endl;

		// explode into crystals
		SpawnCrystals();

		spawner->DestroyPlanetoidFromList(this);


		SetActive(false);
	}
	void Planetoid::SpawnCrystals() {
		for (int i = 0; i <= m_crystals - 1; i++) {
			std::cout << "crystal Spawned" << std::endl;
			new Crystal();
		}
	}
	int Planetoid::GetCrystalNumber() {
		return m_crystals;
	}
}
