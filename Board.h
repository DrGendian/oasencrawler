#pragma once
#include <iostream>
#include "Player.h"
#include "Field.h"
#include "Enemy.h"
class Board
{
	public:
		Board();
		void printBoard();
		void refreshPlayerPosition(Player& player);
		void checkField(Player& player);
		int getRelicAmount();
		void generateBoard();
		void refreshEnemyPosition(Enemy& enemy);

	private:
		Field gameBoard[5][5];
		int relicAmount;
};

