#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "PlayerCharacter.h"
#include "SpriteRenderer.h"

/*
    This version of the SFML "hello world" is statically linked, you may wish to try the dynamically linked version as well.
*/
#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML works!", sf::Style::Titlebar | sf::Style::Close);

    //load texture
    sf::Texture texture("assets/sprites/PLAYER.png", false, sf::IntRect({ 0, 0 }, { 25, 25 }));
    sf::Sprite player1(texture);
    player1.setScale({ 5.0f, 5.0f }); // absolute scale factor
    player1.setPosition({ 10.f, 50.f }); // absolute position

    // initialise player gameobject
    // for some reason causes issues
    LLGP::GameObject* player = new LLGP::GameObject();
    LLGP::SpriteRenderer* playerSpriteRenderer = player->AddComponent<LLGP::SpriteRenderer>();
    // load texture using player sprite renderer
    playerSpriteRenderer->LoadTexture("assets/sprites/PLAYER.png");
    LLGP::PlayerCharacter* playerInput = player->AddComponent<LLGP::PlayerCharacter>();

    std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
    float deltaTime = 0.f;
    float timeSincePhsicsStep = 0.0f;
    const int FIXEDFRAMERATE(50);

    while (window.isOpen())
    {
        // Event polling section of code - this must be done in the thread which created the window
        // we will talk about threading later, but essentially this must be done here
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            //event...
        }

        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 1000000.f;
        lastTime = now;

        timeSincePhsicsStep += deltaTime;
        while (timeSincePhsicsStep > FIXEDFRAMERATE) {
            //step the physics
            //collect collision info
            //dispatch collisions
            timeSincePhsicsStep -= FIXEDFRAMERATE;
        }

        

        window.clear();
        //window.draw(playerSpriteRenderer->GetSprite());
        window.draw(player1);
        window.display();
    }
}