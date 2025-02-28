#include "Enemy.h"
#include <ctime>
#include <iostream>
Enemy::Enemy() {
	y = 3;
	x = 3;
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
	srand(time(NULL));
	int chance = rand() % 4;
	switch(chance) {
	case 0:
		if (x != 4) {
			x++;
		}
		break;
	case 1:
		if (x != 0) {
			x--;
		}
		break;
	case 2:
		if (y != 4) {
			y++;
		}
		break;
	case 3:
		if (x != 0) {
			y--;
		}
		break;
	}

	if (x > 4) {
		x = 4;
	}
	else if (x < 0) {
		x = 0;
	}
	if (y > 4) {
		y = 4;
	}
	else if (y < 0) {
		y = 0;
	}
}

void Enemy::revertPosition() {
		x = lastX;
		y = lastY;
}

void Enemy::printEnemy() {
	std::cout << "Enemy Position:" << "(" << x << "|" << y << ")\n";
}
