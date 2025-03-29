#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "PlayerCharacter.h"
#include "SpriteRenderer.h"

#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
    const float FIXEDFRAMERATE(0.02);
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(FIXEDFRAMERATE);
    // initialise player gameobject
    LLGP::GameObject* player = new LLGP::GameObject();
    LLGP::SpriteRenderer* playerSpriteRenderer = player->AddComponent<LLGP::SpriteRenderer>();
    playerSpriteRenderer->LoadTexture("assets/sprites/PLAYER.png");
    LLGP::PlayerCharacter* playerInput = player->AddComponent<LLGP::PlayerCharacter>();

    std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
    float deltaTime = 0.f;
    float timeSincePhsicsStep = 0.0f;

    while (window.isOpen())
    {
        // Event polling section of code - this must be done in the thread which created the window
        // we will talk about threading later, but essentially this must be done here
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const sf::Event::KeyPressed * keyPress = event->getIf<sf::Event::KeyPressed> ()) {
                //playerInput->Input(playerSpriteRenderer);
            }
        }

        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 1000000.f;
        lastTime = now;

        timeSincePhsicsStep += deltaTime;
        while (timeSincePhsicsStep > FIXEDFRAMERATE) {
            //step the physics
            //collect collision info
            //dispatch collisions

            playerInput->Input(playerSpriteRenderer);
            player->transform->RotateTowards(&window, playerSpriteRenderer);

            timeSincePhsicsStep -= FIXEDFRAMERATE;
        }

        window.clear();
        playerSpriteRenderer->Draw(&window);
        window.display();
    }
}