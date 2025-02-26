#include "Player.h"
#include <iostream>

Player::Player() {
	x = 0;
	y = 0;
	health = 5;
	relics = 0;
}

int Player::changeHealth(int change){
	this->health += change;
	if (this->health > 0) {
		return this->health;
	}
	else {
		return 0;
	}
}

int Player::addRelic() {
	relics += 1;
	return relics;
}

void Player::changePosition(int change,char coord) {
	if (coord == 'x') {
		this->x += change;

		if (this->x > 5) {
			this->x = 5;
		}
		else if (this->x < 0) {
			this->x = 0;
		}
	}
	else if (coord == 'y') {
		this->y += change;

		if (this->y > 5){
			this->y = 5;
		}
		else if (this->y < 0) {
			this->y = 0;
		}
	}
}

int Player::getHealth() {
	return health;
}

int Player::getX() {
	return this->x;
}

int Player::getY() {
	return this->y;
}

void Player::printStats() {
	std::cout << "\nPlayer stats: \nHealth: " << health << "\nCoordinates X|Y:" << "(" << this->x << "|" << this->y << ")";
}