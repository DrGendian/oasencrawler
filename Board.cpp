#include "Board.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <ctime>
Board::Board() : relicAmount(0){
        // Initialize gameBoard with default values
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                gameBoard[i][j] = ' ';
            }
        }

        int x = 0;
        srand((time(NULL)));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                x = rand() % 100 + 1;
                if (x >= 0 && x <= 40) {
                    gameBoard[i][j] = '*';
                }
                else if (x >= 41 && x <= 80) {
                    gameBoard[i][j] = 'G';
                }
                else if (x >= 81 && x <= 90) {
                    gameBoard[i][j] = '2';
                }
                else if (x >= 91 && x <= 100) {
                    gameBoard[i][j] = '#';
					relicAmount++;
                }
            }
        }
    }

void Board::setRelics() {
    int x;
    int y;
    srand(time(NULL));
    for (int i = 0; i <= relicAmount; i++) {
        x = rand() % 5;
        y = rand() % 5;
        gameBoard[x][y] = '#';
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

void Board::checkField(Player& player) {
    int x = player.getX();
    int y = player.getY();
	srand(time(NULL));
    int monsterChance;
    
    if (gameBoard[y][x] == '#') {
        std::cout << "You found a relic!\n";
        player.addRelic();
	}
	else if (gameBoard[y][x] == 'G') {
		monsterChance = rand() % 6 +1;
		if (monsterChance == 3) {
			std::cout << "You found a monster!\n";
			player.changeHealth(-1);
		}
		else {
			std::cout << "You found a monster, but it was sleeping!\n";
		}
	}
    else if (gameBoard[y][x] == '2') {
        std::cout << "You found a well!\n";
        player.changeHealth(1);
    }
}
int Board::getRelicAmount() {
	return relicAmount;
}