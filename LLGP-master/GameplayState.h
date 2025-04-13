#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>

namespace LLGP {
    class StateManager;
    class Player;
    class CrystalManager;
    class Spawner;

    class GameplayState :
        public IGameState
    {
    public:
        GameplayState(sf::RenderWindow* _window, sf::View* _view) :
            window(_window),
            view(_view)
        {
            // Constructor body (if needed)
            std::cout << "GameplayState constructed\n";
        }

        ~GameplayState() override {
            std::cout << "gameplaystate destroyed\n"; 

        }  

        void OnEnter(StateManager* manager) override;
        void OnExit() override;
        void HandleInput() override;
        void Update(float deltaTime) override;
        void FixedUpdate() override;
        void Render(sf::RenderWindow* window) override;

        sf::RenderWindow* window;
		sf::View* view;
    private:
        Player* player;
        Spawner* spawner;
        CrystalManager* crystalManager;
    };

}

