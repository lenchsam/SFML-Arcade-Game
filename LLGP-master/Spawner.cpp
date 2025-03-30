#include "Spawner.h"
#include <cstdlib>
namespace LLGP {
    Spawner::Spawner(GameObject* owner) {
        _GameObject = owner;
    }
    GameObject* Spawner::CreateNewEnemy(sf::RenderWindow* window) {
        GameObject* enemy = new GameObject();
        SpriteRenderer* enemySpriteRenderer = enemy->AddComponent<SpriteRenderer>();

        //add health component here

        enemySpriteRenderer->LoadTexture("assets/sprites/ROCK.png");

        return enemy;
    }
    
    void Spawner::Spawn(sf::RenderWindow* window) {
        GameObject* enemy = CreateNewEnemy(window);

        enemy->GetComponent<SpriteRenderer>()->GetSprite()->setPosition(GetRandomPositionAroundPlayer());

        enemies.push_back(enemy);
    }
    
    void Spawner::DrawAllEnemies(sf::RenderWindow* window) {
        for (auto enemy : enemies) {
            enemy->GetComponent<SpriteRenderer>()->Draw(window);
        }
    }

    sf::Vector2f Spawner::GetRandomPositionAroundPlayer() {
        
        //TODO: change the random numbers to be around the player and not just around the screen
        float x = rand() % 800;
        float y = rand() % 600;
        return sf::Vector2f(x, y);
    }
}
