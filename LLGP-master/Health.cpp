#include "Health.h"
#include "GameObject.h"
LLGP::Health::Health(GameObject* owner) {
	_GameObject = owner;
	m_health = 100.f;
}

float LLGP::Health::GetHealth() {
	return m_health;
}
void LLGP::Health::DealDamage(float damage) {
	m_health -= damage;
	//std::cout << "health = " << m_health << std::endl;
	if (m_health <= 0)
		Die();
}
void LLGP::Health::Die() {
	isDestroyed = true;

	OnEnemyDeath(_GameObject);
	//_GameObject->DestroyThis();
	//std::cout << _GameObject->isDestroyed << std::endl;
	_GameObject->GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color(0, 128, 200));
}