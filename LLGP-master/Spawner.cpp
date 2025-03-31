#include "Spawner.h"
#include <iostream>
#include <random>
using namespace std;
namespace LLGP {
    Spawner::Spawner(GameObject* owner) {
        _GameObject = owner;
    }

    template <typename T>
    T* Spawner::CreateNewEnemy(sf::RenderWindow* window, std::string path) {
        T* enemy = new T();

        //add health component here

        enemy->spriteRenderer->LoadTexture(path);

        return enemy;
    }
    
    void Spawner::Spawn(sf::RenderWindow* window, GameObject* player) {
        if (enemies.size() >= maxEnemiesSpawned) {
            //cout << "done" << endl;
            return;
        }
        
        Asteroid* enemy = CreateNewEnemy<Asteroid>(window, "assets/sprites/ROCK.png");

        enemy->GetComponent<SpriteRenderer>()->GetSprite()->setPosition(GetRandomPositionAroundPlayer(player));



        enemies.push_back(enemy);
    }
    
    void Spawner::MoveAllEnemies(GameObject* player) {
        for (auto enemy : enemies) {
            enemy->GoToTarget(player);
        }
    }

    void Spawner::DrawAllEnemies(sf::RenderWindow* window, GameObject* player) {
        for (auto enemy : enemies) {
            enemy->GoToTarget(player);
            enemy->GetComponent<SpriteRenderer>()->Draw(window);
        }
    }

    sf::Vector2f Spawner::GetRandomPositionAroundPlayer(GameObject* player) {
        
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
