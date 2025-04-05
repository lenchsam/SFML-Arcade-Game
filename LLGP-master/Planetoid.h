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

        void GoToTarget(GameObject* player) override;

    private:
        void RandomMovements();

        float m_MovementSpeed;
    };
}

