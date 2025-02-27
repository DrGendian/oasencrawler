#include "Board.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <ctime>
Board::Board() : relicAmount(0){
        // Initialize gameBoard with default values
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                gameBoard[i][j].symbol = '*';
            }
        }
}

void Board::generateBoard() {
    int x = 0;
    srand((time(NULL)));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            x = rand() % 100 + 1;
            if (x >= 0 && x <= 40) {
                gameBoard[i][j].type = field.EMPTY;
            }
            else if (x >= 41 && x <= 80) {
                gameBoard[i][j].type = field.TRAP;
            }
            else if (x >= 81 && x <= 90) {
                gameBoard[i][j].type = field.WELL;
            }
            else if (x >= 91 && x <= 100) {
                gameBoard[i][j].symbol = '#';
                gameBoard[i][j].type = field.RELIC;
                relicAmount++;
            }
        }
    }
}

void Board::refreshPlayerPosition(Player& player) {
    int lastX = player.getLastX();
    int lastY = player.getLastY();
    this->gameBoard[lastY][lastX].symbol = '*';

    int x = player.getX();
    int y = player.getY();
    this->gameBoard[y][x].symbol = '@';
}

void Board::printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "  " << gameBoard[i][j].symbol;
        }
        std::cout << std::endl;
    }
}

void Board::checkField(Player& player) {
    int x = player.getX();
    int y = player.getY();
	srand(time(NULL));
    int monsterChance;
    
    if (gameBoard[y][x].type == field.RELIC) {
        std::cout << "You found a relic!\n";
        player.addRelic();
        gameBoard[y][x].type = field.EMPTY;
	}
	else if (gameBoard[y][x].type == field.TRAP) {
		monsterChance = rand() % 6 +1;
		if (monsterChance == 3) {
			std::cout << "You found a monster!\n";
			player.changeHealth(-1);
            gameBoard[y][x].type = field.EMPTY;
		}
		else {
			std::cout << "You found a monster, but it was sleeping!\n";
            gameBoard[y][x].type = field.EMPTY;
		}
	}
    else if (gameBoard[y][x].type == field.WELL) {
        std::cout << "You found a well!\n";
        player.changeHealth(1);
        gameBoard[y][x].type = field.EMPTY;
    }
    else {
        std::cout << "You found nothing!\n";
    }

}
int Board::getRelicAmount() {
	return relicAmount;
}