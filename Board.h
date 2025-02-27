#pragma once
#include <iostream>
#include "Player.h"
#include "Field.h"
class Board
{
	public:
		Board();
		Field field;
		void printBoard();
		void refreshPlayerPosition(Player& player);
		void checkField(Player& player);
		int getRelicAmount();
		void generateBoard();

	private:
		Field::strFieldType gameBoard[5][5];
		int relicAmount;
};

