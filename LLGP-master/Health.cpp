#include "Health.h"
LLGP::Health::Health(GameObject* owner) {
	_GameObject = owner;
	m_health = 100.f;
}
