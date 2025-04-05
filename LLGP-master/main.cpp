#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "PlayerCharacter.h"
#include "SpriteRenderer.h"
#include "Spawner.h"
#include "Player.h"
#include "Physics.h"

#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
    const float FIXEDFRAMERATE(0.02);

    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(FIXEDFRAMERATE);

    sf::View view(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));

    // initialise player gameobject
    LLGP::Player* player = new LLGP::Player(&view);


    //initialise the spawner gameobject
    LLGP::Spawner* spawner = new LLGP::Spawner(player);

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
            LLGP::Physics::E_StepPhysics();
            //LLGP::Physics::GetCollisionInfo();
            //LLGP::Physics::DispatchCollisions();
            LLGP::Physics::CheckCollisions();
            player->MoveAllBullets();
            spawner->MoveAllEnemies();

            player->GetComponent<LLGP::PlayerCharacter>()->Input(player);
            player->transform->RotateTowardsMouse(&window);

            timeSincePhsicsStep -= FIXEDFRAMERATE;
        }

        player->Shoot(deltaTime, &window);

        window.clear();

        window.setView(view);

        //draw player and bullets
        player->GetComponent<LLGP::SpriteRenderer>()->Draw(&window);
        player->DrawAllBullets(&window);
        
        //spawn enemies
        spawner->Spawn(&window);
        spawner->DrawAllEnemies(&window);

        window.display();
    }
}