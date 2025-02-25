#pragma once
#include <iostream>
class Board
{
	public:
		Board();
		void printBoard();

	private:
		std::string gameBoard[5][5];
};

