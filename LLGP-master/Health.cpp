#include "Health.h"
#include "GameObject.h"
#include "MakeSound.h"

LLGP::Health::Health(GameObject* owner) {
	_GameObject = owner;
	m_health = 100.f;
	m_maxHealth = 100.f;
}

void LLGP::Health::Init(float maxHealth, int numOfLives) {
	m_maxHealth = maxHealth;
	m_health = maxHealth;
	m_numOfLives = numOfLives;
	isDestroyed = false;
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
	if (m_numOfLives > 0) {
		m_numOfLives--;
		m_health = m_maxHealth;
		return;
	}
	isDestroyed = true;

	MakeSound::PlaySound("Crunch.wav");

	OnEnemyDeath(_GameObject);

	_GameObject->GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color(0, 128, 200));
}