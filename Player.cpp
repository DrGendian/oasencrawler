#include "Player.h"
#include <iostream>

Player::Player() {
	x = 0;
	y = 0;
	health = 5;
	relics = 0;
}

int Player::changeHealth(int change, int health){
	this->health += change;
	if (health > 0) {
		return health;
	}
	else {
		return 0;
	}
}

int Player::addRelic() {
	relics += 1;
	return relics;
}

void Player::changePosition(int change, char coord) {
	if (coord == 'x') {
		x += change;
	}
	else if (coord == 'y') {
		y += change;
	}
}

int Player::getHealth() {
	return health;
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}

void Player::printStats() {
	std::cout << "Player stats: \nHealth: " << health << "\nCoordinates X|Y:" << "(" << x << "|" << y << ")";
}