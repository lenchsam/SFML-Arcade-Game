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
        Transform* transform;

        SpriteRenderer* spriteRenderer;

        void Fire(GameObject* player, sf::RenderWindow* window);

        void MoveBullet();
    private:

        Player* m_player;
        float m_Speed;
        float m_Damage;
        sf::Vector2f m_directionToFire;
    };
}

