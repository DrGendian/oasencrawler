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

void Board::refreshPlayerPosition(Player& player) {
    int lastX = player.getLastX();
    int lastY = player.getLastY();
    this->gameBoard[lastY][lastX] = '*';

    int x = player.getX();
    int y = player.getY();
    this->gameBoard[y][x] = '@';
}

void Board::printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "  " << gameBoard[i][j];
        }
        std::cout << std::endl;
    }
}
