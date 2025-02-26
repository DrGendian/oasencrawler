#pragma once
#include <iostream>
#include "Player.h"
class Board
{
	public:
		Board();
		void printBoard();
		void refreshPlayerPosition(Player& player);

	private:
		char gameBoard[5][5];
};

