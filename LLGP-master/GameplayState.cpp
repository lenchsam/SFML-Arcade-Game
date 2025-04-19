#include "GameplayState.h"
#include "Physics.h"
#include "PlayerCharacter.h"
#include "Game.h"
#include "Player.h"
#include "CrystalManager.h"
#include "Spawner.h"
#include "SpriteRenderer.h"
#include "UI.h"

namespace LLGP{

	void GameplayState::OnEnter(StateManager* manager) {
		std::cout << "Entering Gameplay State" << std::endl;

		//reset score

		player = new Player(view);
		crystalManager = new CrystalManager();
		spawner = new Spawner(player);

		if (!font.openFromFile("assets/CutePixel.ttf"))
		{
			std::cout << "cannot load font" << std::endl;
		}

		CrystalText = UI::AddTextRef("Crystals Collected: 0", { 15.f, 0.f }, 30, sf::Color::White);
		//UI::AddText("HIIIII", { 15.f, 30.f }, 30, sf::Color::White);
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

		std::stringstream ss;
		ss << crystalManager->GetCrystalNumber();
		UI::UpdateText(CrystalText, "Crystals Collected: 1");

		UI::RenderAllText(window);

		window->setView(*view);
	}
}
