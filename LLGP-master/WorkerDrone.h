#pragma once
#include "Enemy.h"
namespace LLGP {
    class Spawner;
    class WorkerDrone :
        public Enemy
    {
	public:
		WorkerDrone();
		~WorkerDrone();

        void Init() override;

        void DestroyThis(Spawner* spawner) override;
        void GoToTarget(GameObject* player) override;

    private:
        float minDistnaceFromPlayer = 50.f;
        sf::Vector2f target;
    };
}

