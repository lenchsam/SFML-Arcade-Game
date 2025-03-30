#include "Spawner.h"
#include <iostream>
#include <random>
using namespace std;
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
    
    void Spawner::Spawn(sf::RenderWindow* window, GameObject* player) {
        if (enemies.size() >= maxEnemiesSpawned) {
            cout << "done" << endl;
            return;
        }

        GameObject* enemy = CreateNewEnemy(window);

        enemy->GetComponent<SpriteRenderer>()->GetSprite()->setPosition(GetRandomPositionAroundPlayer(player));

        enemies.push_back(enemy);
    }
    
    void Spawner::DrawAllEnemies(sf::RenderWindow* window) {
        for (auto enemy : enemies) {
            enemy->GetComponent<SpriteRenderer>()->Draw(window);
        }
    }

    sf::Vector2f Spawner::GetRandomPositionAroundPlayer(GameObject* player) {
        
        //TODO: change the random numbers to be around the player and not just around the screen
        sf::Vector2f playerPosition = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

        int minX = playerPosition.x - spawnRadius;
        int maxX = playerPosition.x + spawnRadius;

        int minY = playerPosition.y - spawnRadius;
        int maxY = playerPosition.y + spawnRadius;

        std::random_device rd;
        std::mt19937 gen(rd());
        uniform_int_distribution<> distribX(minX, maxX);
        uniform_int_distribution<> distribY(minY, maxY);

        int randomValueX = distribX(gen);
        int randomValueY = distribY(gen);

        return sf::Vector2f(randomValueX, randomValueY);
    }
}
