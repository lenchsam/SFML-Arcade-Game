#include "MainMenuState.h"
#include "UI.h"
#include "Button.h"
#include "GameplayState.h"

namespace LLGP {
	void MainMenuState::OnEnter(StateManager* manager) {
		UI::AddText("Play", { 500.f, 500.f }, 30, sf::Color::White, true);
		playButton = new Button(sf::FloatRect({ 475.f, 490.f }, { 50.f, 25.f }));
		quitButton = new Button(sf::FloatRect({ 475.f, 550.f }, { 50.f, 25.f }));
		UI::AddText("Quit", { 500.f, 560.f }, 30, sf::Color::White, true);
	}
	void MainMenuState::OnExit() {
		UI::ClearText();
	}
	void MainMenuState::HandleInput() {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (playButton->ClickCheck(window) == true)
			{
				std::cout << "changed state\n";
				stateManager->ChangeState(std::make_unique<GameplayState>(window));
				return;
			}
			if (quitButton->ClickCheck(window) == true) {
				std::cout << "Clicked Quit Button\n";
				window->close();
				return;
			}
		}
	}
	void MainMenuState::Update(float deltaTime) {

	}
	void MainMenuState::FixedUpdate() {

	}
	void MainMenuState::Render(sf::RenderWindow* window)
	{
		window->setView(*view);
		window->draw(playButton->GetBox());
		window->draw(quitButton->GetBox());
		UI::RenderAllText(window);
		//Render main menu here
	}
}
