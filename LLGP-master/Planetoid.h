#pragma once
#include "Enemy.h"
namespace LLGP {
    class Spawner;
    class Planetoid :
        public Enemy
    {
    public:
        Planetoid();
        ~Planetoid();

        void OnCollision(GameObject* other);
        void Init() override;

        void GoToTarget(GameObject* player) override;

        void DestroyThis(Spawner* spawner) override;

        int GetCrystalNumber();

    private:
        void RandomMovements();

        void SpawnCrystals();

        float m_MovementSpeed;

        int m_crystals = 5;
    };
}

