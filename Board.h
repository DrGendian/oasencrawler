#pragma once
#include <iostream>
#include "Player.h"
class Board
{
	public:
		Board();
		void printBoard();
		void refreshPlayerPosition(Player& player);
		void checkField(Player& player);
		void setRelics();
		int getRelicAmount();

	private:
		char gameBoard[5][5];
		int relicAmount;
};

