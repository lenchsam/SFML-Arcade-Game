#include "GameObject.h"
#include "PlayerCharacter.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Spawner.h"
#include "Health.h"
#include "CircleCollider.h"

namespace LLGP {
	GameObject::GameObject() {
		m_Active = true;
		m_Tag = "Default";
		transform = AddComponent<Transform>();

		GameObject::OnWorldEndFrame += std::bind(&GameObject::OnEndFrame, this);

	}

	void GameObject::SetActive(bool newActive) {
		if (m_Active == newActive) return;

		m_Active = newActive;
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i].get()->OwnerActiveChange(m_Active);
		}
	}

	void GameObject::OnCollision(GameObject* other) {

	}
	void GameObject::OnEndFrame() {
		//if (isDestroyed) {
		//	DestroyThis();
		//}
	}
	void GameObject::DestroyThis(Spawner* spawner) {
		
		std::cout << "GameObject is destroyed" << std::endl;
	}
}

