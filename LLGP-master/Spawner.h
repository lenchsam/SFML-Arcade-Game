#pragma once
#include "Component.h"
#include "GameObject.h"
#include "WorkerDrone.h"
#include "SpriteRenderer.h"
#include "Health.h"
#include <SFML/Graphics.hpp>


namespace LLGP{
    class GameObject;
    class Spawner: public GameObject
    {
    public:
        Spawner(GameObject* player);
        void Spawn(sf::RenderWindow* window, GameObject* player);
        void DrawAllEnemies(sf::RenderWindow* window);
        void MoveAllEnemies();
    private:
        GameObject* _player;
        sf::Vector2f GetRandomPositionAroundPlayer(GameObject* player);
        template <typename T>
        T* CreateNewEnemy(std::string path);
        int spawnRadius = 1000;
        std::vector<Enemy*> enemies;
        int maxEnemiesSpawned = 1;
    };
}


