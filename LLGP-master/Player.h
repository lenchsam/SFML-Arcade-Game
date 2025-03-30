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
        void Shoot(float* deltaTime);
    private:
        float m_shootingSpeed = 1.f;
        float m_Time;
    };
}

