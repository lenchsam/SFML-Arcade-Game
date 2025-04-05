#pragma once
#include "Enemy.h"
namespace LLGP {
    class Planetoid :
        public Enemy
    {
    public:
        Planetoid();
        ~Planetoid();

        void OnCollision(GameObject* other);
        void Init();

    private:
        void RandomMovements();

        float m_MovementSpeed;
    };
}

