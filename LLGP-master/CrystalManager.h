#pragma once
#include <SFML/Graphics.hpp>
#include "Event.h"
namespace LLGP {
	class Crystal;
	class CrystalManager
	{
	public:
		CrystalManager(sf::RenderWindow* _window);
		~CrystalManager();
		void RegisterNewCrystal(Crystal* crystal);
		void RemoveCrystal(Crystal* crystal);
		void GetClosestCrystal(sf::Vector2f pos);
		void DrawAllCrystals();

		static inline LLGP::Event<Crystal*> OnSpawnedCrystal;

	private:
		std::vector<Crystal*> allCrystals;
		sf::RenderWindow* window;
	};
}
