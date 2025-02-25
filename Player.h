#pragma once
class Player
{
	public:
		Player();
		int getY();
		int getX();
		int changeHealth();
		int addRelic();
	private:
		int x;
		int y;
		int health;
		int relics;
};

