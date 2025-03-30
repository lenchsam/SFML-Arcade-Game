#pragma once
#include "GameObject.h"
#include "Health.h"
namespace LLGP {
    class Enemy :
        public GameObject
    {
    public:
        Enemy();
        SpriteRenderer* spriteRenderer;
        Health* health;

    };
}

