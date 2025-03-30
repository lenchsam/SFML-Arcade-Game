#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

namespace LLGP {
    class Player :
        public GameObject
    {
    public:
        Player();
        ~Player();
        void MoveCamera(sf::Vector2f movement);
        sf::View* view;
    private:
    };
}

