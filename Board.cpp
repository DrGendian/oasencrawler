#include "Board.h"
#include "Player.h"
#include <iostream>
Board::Board(){

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->gameBoard[i][j] = '*';
        }
    }
}

void Board::changePlayerPosition(Player& player) {
    int x = player.getX();
    int y = player.getY();

    this->gameBoard[y-1][x-1] = '@';
}

void Board::printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "  " << gameBoard[i][j];
        }
        std::cout << std::endl;
    }
}
