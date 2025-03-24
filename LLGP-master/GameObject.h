#pragma once
#include "Object.h"
#include "Component.h"
#include "ComponentConcepts.h"
#include "Transform.h"
#include <vector>
#include <memory>

namespace LLGP {
	class GameObject : public Object
	{
	public:
		GameObject();
		GameObject(const GameObject&) = default;
		Transform* transform;
		inline void SetName(std::string newName) { m_Name = newName; }
		inline std::string GetName() { return m_Name; }

		void SetActive(bool newActive);
		inline bool GetActive() { return m_Active; }

		inline void SetTag(std::string newTag) { m_Tag = newTag; }
		inline bool CompareTag(std::string comp) { return m_Tag == comp; }

		template<class T> requires isComponent<T> T* GetComponent();
		template<class T> requires isComponent<T> T* AddComponent();
		
		//template<class T> requires isComponent<T>
		//T* AddComponent() {
		//	std::unique_ptr<Component> newComp = std::make_unique<T>(this);
		//	m_Components.push_back(std::move(newComp));
		//	return static_cast<T*>(m_Components[m_Components.size() - 1].get());
		//}

		template<class T> requires isComponent<T> bool RemoveComponent(T* comp);

	private:
		std::string m_Name;
		bool m_Active;
		std::string m_Tag;
		std::vector<std::unique_ptr<Component>> m_Components;
	public:
		inline bool operator==(const GameObject& other) { return this->uuid == other.uuid; }
		inline bool operator!=(const GameObject& other) { return !(*this == other); }
	};
}


