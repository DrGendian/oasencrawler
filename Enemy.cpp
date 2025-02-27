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
}