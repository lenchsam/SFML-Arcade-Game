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
    };
}

