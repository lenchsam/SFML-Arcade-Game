#pragma once
#include "Enemy.h"
namespace LLGP {
    class WorkerDrone :
        public Enemy
    {
    public:
        WorkerDrone();
        ~WorkerDrone();
        void Init();
    private:
        sf::Vector2f target;
    };
}

