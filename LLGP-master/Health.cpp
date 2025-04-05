#include "Health.h"
LLGP::Health::Health(GameObject* owner) {
	_GameObject = owner;
	m_health = 100.f;
}

float LLGP::Health::GetHealth() {
	return m_health;
}
void LLGP::Health::DealDamage(float damage) {
	m_health -= damage;
	std::cout << "health = " << m_health << std::endl;
}
void LLGP::Health::Die() {

}