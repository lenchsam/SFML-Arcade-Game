#include "GameplayState.h"
#include "Physics.h"
#include "PlayerCharacter.h"
#include "Game.h"
#include "Player.h"
#include "CrystalManager.h"
#include "Spawner.h"
#include "SpriteRenderer.h"

namespace LLGP{

	void GameplayState::OnEnter(StateManager* manager) {
		std::cout << "Entering Gameplay State\n";

		UIView = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
		//load all scene data
		//create player
		//reset score

		player = new Player(view);
		crystalManager = new CrystalManager();
		spawner = new Spawner(player);

		if (!font.openFromFile("assets/CutePixel.ttf"))
		{
			std::cout << "cannot load font" << std::endl;
		}
	}
	void GameplayState::OnExit() {
		std::cout << "Exiting Gameplay State\n";

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

		HandleInput();

		player->transform->RotateTowardsMouse(window);
		spawner->RotateTowardsPlayer(player);
	}
	void GameplayState::Render(sf::RenderWindow* window) {
		LLGP::SpriteRenderer::RenderSprite(window);

		spawner->Spawn(window);
		spawner->DrawAllEnemies(window);
		crystalManager->DrawAllCrystals(window);

		//render UI Here
		window->setView(*UIView);

		sf::Text text(font);

		std::stringstream ss;
		ss << crystalManager->GetCrystalNumber();
		text.setString("Crystals Collected: " + ss.str());
		text.setCharacterSize(35);

		window->draw(text);

		window->setView(*view);
	}
}
