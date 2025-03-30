#pragma once
#include "Enemy.h"
#include <cmath>
namespace LLGP {
    class Asteroid :
        public Enemy
    {
    public:
        Asteroid();
        ~Asteroid();
        void GoToTarget(GameObject* player);
    private:
        sf::Vector2f target;
    };
}

