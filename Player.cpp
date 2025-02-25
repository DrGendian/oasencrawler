#include "Player.h"

Player::Player() {
	x = 0;
	y = 0;
	health = 5;
	relics = 0;
}

int Player::changeHealth(int change, int health){
	health += change;
	if (health > 0) {
		return health;
	}
	else {
		return 0;
	}
}

int Player::getHealth() {
	return health;
}