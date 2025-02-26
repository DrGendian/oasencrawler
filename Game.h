#pragma once
#include "Player.h"

class Game
{
	public:
		Game();
		void startGame();
		char getInput(Player&);

	private:
		char input;
		int relicAmount;
};

