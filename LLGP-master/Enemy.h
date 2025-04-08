#pragma once
#include "GameObject.h"
#include "Health.h"
namespace LLGP {
    class CircleCollider;
    class Spawner;
    class Enemy :
        public GameObject
    {
    public:
        Enemy();
        SpriteRenderer* spriteRenderer;
        Health* health;
        virtual void GoToTarget(GameObject* player);
        virtual void Init();
        float m_speed = 2.f;
        void OnCollision(GameObject* other) override;

        void RotateTowardsPlayer(GameObject* player);

        void DestroyThis(Spawner* spawner) override;
    protected:
        CircleCollider* circleCollider;

        //void OnEndFrame();
    };
}

