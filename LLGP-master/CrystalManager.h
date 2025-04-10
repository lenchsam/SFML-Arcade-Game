#pragma once
#include <SFML/Graphics.hpp>
namespace LLGP {
	class Crystal;
	class CrystalManager
	{
	public:
		CrystalManager() {}
		~CrystalManager() {}
		void RegisterNewCrystal(Crystal* crystal);
		void RemoveCrystal(Crystal* crystal);
		void GetClosestCrystal(sf::Vector2f pos);
		void DrawAllCrystals(sf::RenderWindow* window);

	private:
		std::vector<Crystal*> allCrystals;
	};
}
