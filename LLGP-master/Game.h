#pragma once
#include <SFML/Graphics.hpp>

namespace LLGP {

	class Player;
	class CrystalManager;
	class Spawner;

	class Game
	{
	public:
		Game();
		void run();

	private:
		sf::RenderWindow window;
		sf::FloatRect mapBounds;
		sf::View* view;

		Player* player;
		Spawner* spawner;
		CrystalManager* crystalManager;

		float timeSincePhsicsStep = 0.0f;
		float time = 0;

		void Update(float deltaTime);
		void FixedUpdate();
		void Render();
	};
}

