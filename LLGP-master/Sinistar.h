#pragma once
#include "Enemy.h"
namespace LLGP {
    class Sinistar :
        public Enemy
    {
    public:
        Sinistar();
        ~Sinistar();
        void Init() override;

        void DestroyThis(Spawner* spawner) override;
        void GoToTarget(GameObject* player, sf::Vector2f target) override;
        sf::Vector2f ChooseTarget(sf::Vector2f playerPosition);

    private:
        sf::Vector2f m_target;
        std::vector<sf::Vector2f> targetPositions;

        bool isDashing = false;
        bool justDashed = false;
        float m_dashSpeedMultiplier = 2.f;
        float m_waitTimeAfterDash = 0.5f;
    };
}

