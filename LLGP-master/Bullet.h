#pragma once
#include "GameObject.h"
#include "Player.h"
#include "SpriteRenderer.h"

namespace LLGP {
    class Bullet :
        public GameObject
    {
    public:
        Bullet();
        ~Bullet();
        void SetPlayer(Player* player);

        SpriteRenderer* spriteRenderer;

    private:
        void Fire();

        Player* m_player;
        float m_Speed;
        float m_Damage;
    };
}

