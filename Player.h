#pragma once
class Player
{
	public:
		Player();
		int getY();
		int getX();
		int getLastY();
		int getLastX();
		int changeHealth(int);
		int addRelic();
		int getHealth();
		void printStats();
		void changePosition(int, char);
	private:
		int x;
		int lastX;
		int y;
		int lastY;
		int health;
		int relics;
};

