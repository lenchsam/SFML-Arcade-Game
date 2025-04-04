#pragma once
#include "GameObject.h"
namespace LLGP {
    class Planetoid :
        public GameObject
    {
    public:
        Planetoid();
        ~Planetoid();

        void OnCollision(GameObject* other);

    private:
        void RandomMovements();

        float m_MovementSpeed;
    };
}

