#pragma once
#include <iostream>
#include "Player.h"
class Board
{
	public:
		Board();
		void printBoard();
		void refreshPlayerPosition(Player& player);
		void checkForRelic(Player& player);
		void setRelics();

	private:
		char gameBoard[5][5];
};

