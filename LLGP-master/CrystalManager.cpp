#include "CrystalManager.h"
#include "SpriteRenderer.h"
#include "Crystal.h"
#include "Scoring.h"
namespace LLGP {
	CrystalManager::CrystalManager() {
		CrystalManager::OnSpawnedCrystal += std::bind(&CrystalManager::RegisterNewCrystal, this, std::placeholders::_1);
		CrystalManager::OnCollectedCrystal += std::bind(&CrystalManager::RemoveCrystal, this, std::placeholders::_1);

	}
	CrystalManager::~CrystalManager() {
	}
	void CrystalManager::DrawAllCrystals(sf::RenderWindow* window) {
		for (auto crystal : allCrystals) {
			crystal->GetComponent<SpriteRenderer>()->Draw(window);
		}
	}

	void CrystalManager::CreateBomb() {
		if (crystalsCollected >= crystalsForBomb) {
			numBombs++;
		}
	}

	int CrystalManager::GetCrystalNumber() {
		return crystalsCollected;
	}

	void CrystalManager::RegisterNewCrystal(Crystal* crystal) {
		allCrystals.push_back(crystal);
	}

	void CrystalManager::RemoveCrystal(Crystal* crystal) {
		allCrystals.erase(std::remove(allCrystals.begin(), allCrystals.end(), crystal), allCrystals.end());
		crystal->SetActive(false);

		Scoring::OnDeath(CRYSTAL);
		std::cout << "updatedScoreEvent " << std::endl;

		crystalsCollected++;
	}

}
