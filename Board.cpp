#include "Board.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
Board::Board(){

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->gameBoard[i][j] = '*';
        }
    }
}

char Board::changePlayerPosition(Player& player) {
    int x = player.getX();
    int y = player.getY();
	char input;

	gameBoard[y - 1][x - 1] = '*';

	std::cout << "\nEnter Direction (W/A/S/D) ";
	std::cin >> input;

	switch (input) {
	case 'w':
		player.changePosition(-1, 'y');
		break;
	case 's':
		player.changePosition(1, 'y');
		break;
	case 'a':
		player.changePosition(1, 'x');
		break;
	case 'd':
		player.changePosition(-1, 'x');
		break;
	default:
		std::cout << "Wrong Input!";
	}

	x = player.getX();
	y = player.getY();

    gameBoard[y-1][x-1] = '@';

	return input;
}

void Board::printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "  " << gameBoard[i][j];
        }
        std::cout << std::endl;
    }
}
