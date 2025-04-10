#include "CrystalManager.h"
#include "SpriteRenderer.h"
#include "Crystal.h"
namespace LLGP {
	void CrystalManager::DrawAllCrystals(sf::RenderWindow* window) {
		for (auto crystal : allCrystals) {
			crystal->GetComponent<SpriteRenderer>()->Draw(window);
		}
	}

	void CrystalManager::RegisterNewCrystal(Crystal* crystal) {
		allCrystals.push_back(crystal);
	}

}
