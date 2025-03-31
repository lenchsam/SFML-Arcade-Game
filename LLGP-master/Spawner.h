#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Asteroid.h"
#include "SpriteRenderer.h"
#include "Health.h"
#include <SFML/Graphics.hpp>


namespace LLGP{
    class GameObject;
    class Spawner: public Component
    {
    public:
        Spawner(GameObject* owner);
        void Spawn(sf::RenderWindow* window, GameObject* player);
        void DrawAllEnemies(sf::RenderWindow* window);
        void MoveAllEnemies(GameObject* player);
    private:
        sf::Vector2f GetRandomPositionAroundPlayer(GameObject* player);
        template <typename T>
        T* CreateNewEnemy(std::string path);
        GameObject* _GameObject;
        int spawnRadius = 1000;
        std::vector<Enemy*> enemies;
        int maxEnemiesSpawned = 5;
    };
}


