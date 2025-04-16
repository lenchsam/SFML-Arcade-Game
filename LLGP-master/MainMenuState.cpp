#include "MainMenuState.h"
#include "UI.h"

namespace LLGP {
	void MainMenuState::OnEnter(StateManager* manager) {
		UI::AddText("PLAY", { 500.f, 470.f }, 30, sf::Color::White);
		UI::AddText("OPTIONS", { 500.f, 550.f }, 30, sf::Color::White);
		UI::AddText("QUIT", { 500.f, 560.f }, 30, sf::Color::White);
	}
	void MainMenuState::OnExit() {

	}
	void MainMenuState::HandleInput() {

	}
	void MainMenuState::Update(float deltaTime) {

	}
	void MainMenuState::FixedUpdate() {

	}
	void MainMenuState::Render(sf::RenderWindow* window)
	{
		window->setView(*view);
		UI::RenderAllText(window);
		//Render main menu here
	}
}
