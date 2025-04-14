#pragma once
#include <SFML/Graphics.hpp>
#include "Event.h"
namespace LLGP {
	class Crystal;
	class CrystalManager
	{
	public:
		CrystalManager();
		~CrystalManager();
		void RegisterNewCrystal(Crystal* crystal);
		void RemoveCrystal(Crystal* crystal);
		void GetClosestCrystal(sf::Vector2f pos);
		void DrawAllCrystals(sf::RenderWindow* window);
		int GetCrystalNumber();
		void CreateBomb();

		static inline LLGP::Event<Crystal*> OnSpawnedCrystal;
		static inline LLGP::Event<Crystal*> OnCollectedCrystal;

	private:
		std::vector<Crystal*> allCrystals;

		int crystalsCollected = 0;
		int crystalsForBomb = 5;
		int numBombs;
	};
}
