#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game
{
	public:
		Game();
		void startGame();
		char getInput(Player&);

	private:
		char input;
		std::vector<Enemy> enemyCount;
};

