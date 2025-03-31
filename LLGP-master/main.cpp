#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "PlayerCharacter.h"
#include "SpriteRenderer.h"
#include "Spawner.h"
#include "Player.h"

#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
    const float FIXEDFRAMERATE(0.02);

    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(FIXEDFRAMERATE);


    // initialise player gameobject
    LLGP::Player* player = new LLGP::Player();
    sf::View view(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
    player->view = &view;
    LLGP::SpriteRenderer* playerSpriteRenderer = player->AddComponent<LLGP::SpriteRenderer>();
    playerSpriteRenderer->LoadTexture("assets/sprites/PLAYER.png");
    LLGP::PlayerCharacter* playerInput = player->AddComponent<LLGP::PlayerCharacter>();


    //initialise the spawner gameobject
    LLGP::GameObject* spawner = new LLGP::GameObject();
    LLGP::Spawner* spawnerComponent = spawner->AddComponent<LLGP::Spawner>();

    std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
    float deltaTime = 0.f;
    float timeSincePhsicsStep = 0.0f;

    float time = 0;

    while (window.isOpen())
    {
        // Event polling section of code - this must be done in the thread which created the window
        // we will talk about threading later, but essentially this must be done here
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        //deltaTime
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 1000000.f;
        lastTime = now;

        timeSincePhsicsStep += deltaTime;
        while (timeSincePhsicsStep > FIXEDFRAMERATE) {
            //step the physics
            //collect collision info
            //dispatch collisions


            playerInput->Input(player);


            player->transform->RotateTowards(&window);

            timeSincePhsicsStep -= FIXEDFRAMERATE;
        }

            //if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            player->Shoot(deltaTime);
            //}

        window.clear();


        window.setView(view);
        //draw player
        playerSpriteRenderer->Draw(&window);
        player->DrawAllBullets(&window);
        
        spawnerComponent->MoveAllEnemies(player);

        //spawn enemies
        spawnerComponent->Spawn(&window, player);
        spawnerComponent->DrawAllEnemies(&window);

        window.display();
    }
}