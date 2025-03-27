#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>

namespace LLGP {
	class Transform : public Component
	{
	public:
		Transform(GameObject* owner);

		void SetPosition();
		sf::Vector2f GetPosition();
		void ChangePosition(sf::Vector2f distance);
		sf::Vector2f m_Position;
	};
}

