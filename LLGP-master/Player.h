#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

namespace LLGP {
    class Player :
        public GameObject
    {
    public:
        Player();
        ~Player();
        void MoveCamera(sf::Vector2f movement);
        sf::View* view;
        void Shoot(float deltaTime);
        void DrawAllBullets(sf::RenderWindow* window);
    private:
        std::vector<GameObject*> _Bullets;
        float m_shootingSpeed = 0.5f;
        float m_time = 0;
    };
}

