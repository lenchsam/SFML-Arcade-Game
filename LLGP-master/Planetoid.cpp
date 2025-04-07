#include "Planetoid.h"
#include "CircleCollider.h"
#include "Bullet.h"
namespace LLGP {
	Planetoid::Planetoid() {
		circleCollider->SetRadius(25.f);
	}
	Planetoid::~Planetoid() {

	}
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
}
