#pragma once
class Enemy
{
public:
	Enemy();
	int getY();
	int getX();
	int getLastY();
	int getLastX();
	void changePosition();
	void printEnemy();
	void revertPosition();
	char symbol = 'V';
private:
	int x;
	int lastX;
	int y;
	int lastY;
};