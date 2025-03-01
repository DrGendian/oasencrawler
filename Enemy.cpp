#include "Enemy.h"
#include "Board.h"
#include "Player.h"
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
void Enemy::changePosition(Player& player) {
	lastX = x;
	lastY = y;
	/*srand(time(NULL));
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
	}*/
	

	
	int playerX = player.getX();
	int playerY = player.getY();

	int differenceX = playerX - x;
	int differenceY = playerY - y;

	if (x != playerX) {
		x += (playerX > x) ? 1 : -1;
	}
	else if (y != playerY) {
		y += (playerY > y) ? 1 : -1;
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
		x = 4;
		y = 4;
}

void Enemy::printEnemy() {
	std::cout << "Enemy Position:" << "(" << x << "|" << y << ")\n";
}
