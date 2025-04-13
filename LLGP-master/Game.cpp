#include "Game.h"
#include "Player.h"
#include "Physics.h"
#include "PlayerCharacter.h"
#include "Spawner.h"
#include "CrystalManager.h"
#include "GameplayState.h"
#include <memory>

#define FIXEDFRAMERATE 60
const float FIXED_UPDATE_TIMER = 1.0f / 60.0f;

namespace LLGP {
    Game::Game()
        : window(sf::VideoMode({ 1000, 1000 }), "SFML works!", sf::Style::Titlebar | sf::Style::Close) {

        view = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
        mapBounds = sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }); // For example, a 1000x1000 world

        auto gameplayState = std::make_unique<GameplayState>(
            &this->window, 
            this->view 
        );
        stateManager.InitialiseStateMachine(std::move(gameplayState));
    }

    static std::chrono::steady_clock::time_point lastFixedUpdate = std::chrono::steady_clock::now();

    void Game::run() {
        std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
        float deltaTime = 0.f;

        while (window.isOpen()) {
            auto now = std::chrono::steady_clock::now();
            deltaTime = std::chrono::duration<float>(now - lastTime).count();
            lastTime = now;

            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            //deltaTime
            auto timeSinceFixedUpdate = std::chrono::duration<float>(now - lastFixedUpdate).count();

            if (timeSinceFixedUpdate > FIXED_UPDATE_TIMER) {
                stateManager.FixedUpdate();
                lastFixedUpdate = now;
            }

            stateManager.Update(deltaTime);
            Render();
        }
    }

    void Game::Render() {
        window.clear();
        window.setView(*view);

        stateManager.Render(&window);

        window.display();    
        GameObject::OnWorldEndFrame();
    }

}
