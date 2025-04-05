#pragma once
#include "Enemy.h"
namespace LLGP {
    class WarriorDrone :
        public Enemy
    {
    public:
        WarriorDrone();
        ~WarriorDrone();
        void Init() override;
    private:
        sf::Vector2f target;
    };
}

