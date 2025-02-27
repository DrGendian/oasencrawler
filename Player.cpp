#include "Player.h"
#include <iostream>

Player::Player() {
	x = 0;
	lastX = 0;
	y = 0;
	lastY = 0;
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
		lastX = x;
		lastY = y;
	if (coord == 'x') {
		this->x += change;

		if (this->x > 4) {
			this->x = 4;
		}
		else if (this->x < 0) {
			this->x = 0;
		}
	}
	else if (coord == 'y') {
		this->y += change;

		if (this->y > 4){
			this->y = 4;
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

int Player::getLastY() {
	return lastY;
}
int Player::getLastX() {
	return lastX;
}

int Player::getRelics() {
	return relics;
}

void Player::printStats() {
	std::cout << "\nPlayer stats: \nHealth: " << health << "\nRelics: " << relics << "\nCoordinates X|Y:" << "(" << this->x << "|" << this->y << ")";
}