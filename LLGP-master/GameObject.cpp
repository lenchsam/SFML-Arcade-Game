#include "GameObject.h"
#include "PlayerCharacter.h"
#include "SpriteRenderer.h"

namespace LLGP {
	GameObject::GameObject() {
		m_Active = true;
		m_Tag = "Default";
	}
	template<class T> requires isComponent<T>
	T* GameObject::GetComponent() {
		T* returnComp = nullptr;
		for (int i = 0; i < m_Components.size(); i++) {

			returnComp = static_cast<T*>(m_Components[i].get());
			if (returnComp != nullptr) {
				break;
			}
		}

		return returnComp;
	}

	template<class T> requires isComponent<T>
	T* GameObject::AddComponent() {
		std::unique_ptr<Component> newComp = std::make_unique<T>(this);
		m_Components.push_back(std::move(newComp));
		return static_cast<T*>(m_Components[m_Components.size() - 1].get());
	}

	template PlayerCharacter* GameObject::AddComponent<PlayerCharacter>();
	template SpriteRenderer* GameObject::AddComponent<SpriteRenderer>();
}

