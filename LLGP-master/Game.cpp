#include "Game.h"
#include "Player.h"
#include "Physics.h"
#include "PlayerCharacter.h"
#include "Spawner.h"
#include "CrystalManager.h"

#define FIXEDFRAMERATE 60
const float FIXED_UPDATE_TIMER = 1.0f / 60.0f;

namespace LLGP {
    Game::Game()
        : window(sf::VideoMode({ 1000, 1000 }), "SFML works!", sf::Style::Titlebar | sf::Style::Close) {

        view = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
        mapBounds = sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }); // For example, a 1000x1000 world

        //INITIALISE ALL GAMEOBJECTS
        player = new Player(view);
        crystalManager = new CrystalManager();
        spawner = new Spawner(player);
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
                FixedUpdate();
                lastFixedUpdate = now;
            }

            Update(deltaTime);
            Render();
        }
    }

    void Game::Update(float deltaTime) {
        // Update game logic here

        player->Shoot(deltaTime, &window);


    }

    void Game::FixedUpdate() {
        LLGP::Physics::StepPhysics();

        LLGP::Physics::CheckCollisions();

        player->GetComponent<LLGP::PlayerCharacter>()->Input(player);

        player->transform->RotateTowardsMouse(&window);
        spawner->RotateTowardsPlayer(player);
    }

    void Game::Render() {
        window.clear();
        window.setView(*view);

        LLGP::SpriteRenderer::RenderSprite(&window);

        spawner->Spawn(&window);
        spawner->DrawAllEnemies(&window);
        crystalManager->DrawAllCrystals(&window);

        window.display();    
        GameObject::OnWorldEndFrame();
    }

}
