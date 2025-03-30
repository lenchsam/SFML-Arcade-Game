#pragma once
#include "Component.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include <SFML/Graphics.hpp>


namespace LLGP{
    class GameObject;
    class Spawner: public Component
    {
    public:
        Spawner(GameObject* owner);
        void Spawn(sf::RenderWindow* window, GameObject* player);
        void DrawAllEnemies(sf::RenderWindow* window);
    private:
        sf::Vector2f GetRandomPositionAroundPlayer(GameObject* player);
        GameObject* CreateNewEnemy(sf::RenderWindow* window);
        GameObject* _GameObject;
        int spawnRadius = 1000;
        std::vector<GameObject*> enemies;
        int maxEnemiesSpawned = 5;
    };
}


