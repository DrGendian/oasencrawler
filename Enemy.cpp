#include "Enemy.h"
#include "Board.h"
#include "Player.h"
#include <ctime>
#include <iostream>
Enemy::Enemy() {
	srand(time(NULL));
	y = rand() % 5;
	x = rand() % 5;
	lastY = y;
	lastX = x;
}

int Enemy::getX() {
	return this->x;
}

int Enemy::getY() {
	return this->y;
}

int Enemy::getLastY() {
	return lastY;
}
int Enemy::getLastX() {
	return lastX;
}


void Enemy::changePosition() {
	lastX = x;
	lastY = y;
	int chance = rand() % 4;
	switch (chance) {
	case 0: x--; break;
	case 1: x++; break;
	case 2: y++; break;
	case 3: y--; break;
	}

	if (x < 0) x = 0;
	if (x > 4) x = 4;
	if (y < 0) y = 0;
	if (y > 4) y = 4;
}

void Enemy::revertPosition() {
		x = lastX;
		y = lastY;
}

void Enemy::printEnemy() {
	std::cout << "Enemy Position:" << "(" << y << "|" << x << ")\n";
}
