#pragma once
class Player
{
	public:
		Player();
		int getY();
		int getX();
		int changeHealth(int change, int health);
		int addRelic();
		int getHealth();
	private:
		int x;
		int y;
		int health;
		int relics;
};

