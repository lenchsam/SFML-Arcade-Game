#include "GameplayState.h"
#include "Physics.h"
#include "PlayerCharacter.h"
#include "Game.h"
#include "Player.h"
#include "CrystalManager.h"
#include "Spawner.h"
#include "SpriteRenderer.h"
#include "UI.h"
#include "Scoring.h"

namespace LLGP{

	void GameplayState::OnEnter(StateManager* manager) {
		std::cout << "Entering Gameplay State" << std::endl;

		//reset score

		player = new Player(view);
		crystalManager = new CrystalManager();
		spawner = new Spawner(player);

		minimapView->setCenter(player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition());

		if (!font.openFromFile("assets/CutePixel.ttf"))
		{
			std::cout << "cannot load font" << std::endl;
		}

		crystalTextIndex = UI::AddText("Crystals Collected: 0", { 75.f, 75.f }, 30, sf::Color::White, false);
		scoreTextIndex = UI::AddText("Score: 0", { 75.f, 100.f }, 30, sf::Color::White, false);
		bombTextIndex = UI::AddText("Bombs: 0", { 75.f, 125.f }, 30, sf::Color::White, false);

		CrystalManager::OnMadeBomb += std::bind(&GameplayState::UpdateBombText, this);
		CrystalManager::OnCollectedCrystal += std::bind(&GameplayState::UpdateCrystalText, this);
		Scoring::ScoreChanged += std::bind(&GameplayState::UpdateScoreText, this, std::placeholders::_1);

	}
	void GameplayState::OnExit() {
		std::cout << "Exiting Gameplay State" << std::endl;

		//unload scene
	}
	void GameplayState::HandleInput() {
		player->GetComponent<LLGP::PlayerCharacter>()->Input(player);
	}
	void GameplayState::Update(float deltaTime) {
		player->Shoot(deltaTime, window);
	}
	void GameplayState::FixedUpdate() {
		LLGP::Physics::StepPhysics();

		LLGP::Physics::CheckCollisions();

		player->transform->RotateTowardsMouse(window);
		spawner->RotateTowardsPlayer(player);
	}
	void GameplayState::Render(sf::RenderWindow* window) {
		window->setView(*view);

		LLGP::SpriteRenderer::RenderSprite(window);

		spawner->Spawn(window);
		spawner->DrawAllEnemies(window);
		crystalManager->DrawAllCrystals(window);

		//render UI Here
		window->setView(*UIView);

		UI::RenderAllText(window);
		window->setView(*minimapView);

		LLGP::SpriteRenderer::RenderSprite(window);
		spawner->Spawn(window);
		spawner->DrawAllEnemies(window);
		crystalManager->DrawAllCrystals(window);

		window->setView(*view);
	}

	void GameplayState::UpdateScoreText(int currentScore) {
		std::stringstream ss;
		ss << "Score: " << currentScore;
		UI::UpdateText(scoreTextIndex, ss.str());
	}
	void GameplayState::UpdateBombText() {
		std::stringstream ss;
		ss << "Bombs: " << crystalManager->GetBombNumber();
		UI::UpdateText(bombTextIndex, ss.str());
	}
	void GameplayState::UpdateCrystalText() {
		std::stringstream ss;
		ss << "Crystals Collected: " << crystalManager->GetCrystalNumber();
		UI::UpdateText(crystalTextIndex, ss.str());
	}
}
