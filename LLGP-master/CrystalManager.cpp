#include "CrystalManager.h"
#include "SpriteRenderer.h"
#include "Crystal.h"
namespace LLGP {
	CrystalManager::CrystalManager(sf::RenderWindow* _window) {
		CrystalManager::OnSpawnedCrystal += std::bind(&CrystalManager::RegisterNewCrystal, this, std::placeholders::_1);

		window = _window;
	}
	CrystalManager::~CrystalManager() {

	}
	void CrystalManager::DrawAllCrystals() {
		for (auto crystal : allCrystals) {
			crystal->GetComponent<SpriteRenderer>()->Draw(window);
		}
	}

	void CrystalManager::RegisterNewCrystal(Crystal* crystal) {
		allCrystals.push_back(crystal);
	}

}
