#pragma once
class Player
{
	public:
		Player();
		int getY();
		int getX();
		int changeHealth(int);
		int addRelic();
		int getHealth();
		void printStats();
		void changePosition(int, char);
	private:
		int x;
		int y;
		int health;
		int relics;
};

