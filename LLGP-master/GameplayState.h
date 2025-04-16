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
        GameplayState(sf::RenderWindow* _window) :
            window(_window)
        {
            view = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
            UIView = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
            std::cout << "GameplayState constructed" << std::endl;
        }

        ~GameplayState() override {
            std::cout << "gameplaystate destroyed" << std::endl;

        }  

        void OnEnter(StateManager* manager) override;
        void OnExit() override;
        void HandleInput() override;
        void Update(float deltaTime) override;
        void FixedUpdate() override;
        void Render(sf::RenderWindow* window) override;

    private:
        sf::RenderWindow* window;
		sf::View* view;

        Player* player;
        Spawner* spawner;
        CrystalManager* crystalManager;

        sf::View* UIView;
        sf::Font font;
    };

}

