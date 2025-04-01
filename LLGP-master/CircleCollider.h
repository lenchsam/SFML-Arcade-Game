#pragma once
#include "Collider.h"
namespace LLGP {
    class GameObject;
    class CircleCollider :
        public Collider
    {
    public:
        CircleCollider(GameObject* owner);
        ~CircleCollider();

        void SetRadius(float radius);
    private:
        float m_Radius;
        GameObject* _GameObject;
    };
}

