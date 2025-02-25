#include "Board.h"
#include <iostream>
Board::Board(){

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->gameBoard[i][j] = "*";
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "  " << gameBoard[i][j];
        }
        std::cout << std::endl;
    }
}
