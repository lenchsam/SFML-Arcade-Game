#include "Player.h"

namespace LLGP {
	Player::Player() {

	}
	Player::~Player() {
		delete view;
	}
	void Player::MoveCamera(sf::Vector2f movement) {
		view->move(movement);
	}
}
