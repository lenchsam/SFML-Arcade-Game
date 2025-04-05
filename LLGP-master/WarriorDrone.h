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

        void GoToTarget(GameObject* player) override;
    private:
        float minDistnaceFromPlayer = 50.f;
        sf::Vector2f target;
    };
}

