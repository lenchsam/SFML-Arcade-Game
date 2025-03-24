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
	private:
		sf::Vector2f m_Position;

	};
}

