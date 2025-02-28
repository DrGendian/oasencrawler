#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
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
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            x = rand() % 100 + 1;
            if (x >= 0 && x <= 40) {
                gameBoard[i][j].type = Field::EMPTY;
            }
            else if (x >= 41 && x <= 80) {
                gameBoard[i][j].type = Field::TRAP;
                gameBoard[i][j].symbol = '!';
            }
            else if (x >= 81 && x <= 90) {
                gameBoard[i][j].type = Field::WELL;
            }
            else if (x >= 91 && x <= 100) {
                if (gameBoard[i][j].type != Field::ENEMY) {
                    gameBoard[i][j].symbol = '#';
                    gameBoard[i][j].type = Field::RELIC;
                    relicAmount++;
                }
            }
        }
    }
}
//refreshes position of player. Changes the last position to a *
void Board::refreshPlayerPosition(Player& player) {
    int lastX = player.getLastX();
    int lastY = player.getLastY();
    this->gameBoard[lastY][lastX].symbol = '*';

    int x = player.getX();
    int y = player.getY();
    this->gameBoard[y][x].symbol = '@';
}
//changes enemy position every turn
void Board::refreshEnemyPosition(Enemy& enemy) {
    int lastX = enemy.getLastX();
    int lastY = enemy.getLastY();
    this->gameBoard[lastY][lastX].symbol = '*';
    //FOR LATER USE IN HIGHER DIFFICULTY
    //gameBoard[lastY][lastX].symbol = '!';
    //gameBoard[lastY][lastX].type = Field::TRAP;

    int x = enemy.getX();
    int y = enemy.getY();

    if (gameBoard[y][x].symbol != Field::RELIC) {
        this->gameBoard[y][x].symbol = 'V';
        gameBoard[y][x].type = Field::ENEMY;
    }
    else {
        enemy.revertPosition();
    }
    
}

void Board::printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "  " << gameBoard[i][j].symbol;
        }
        std::cout << std::endl;
    }
}
//Checks what type of field the player is on
void Board::checkField(Player& player) {
    int x = player.getX();
    int y = player.getY();
    srand(static_cast<unsigned int>(time(NULL)));
    int monsterChance;
    if (gameBoard[y][x].type == Field::ENEMY) {
        std::cout << "Enemy\n";
        player.revertPosition();
        player.changeHealth(-1);
     }else if (gameBoard[y][x].type == Field::RELIC) {
        std::cout << "You found a relic!\n";
        player.addRelic();
        gameBoard[y][x].type = Field::EMPTY;
	}else if (gameBoard[y][x].type == Field::TRAP) {
		monsterChance = rand() % 6 +1;
		if (monsterChance == 4) {
			std::cout << "You found a monster!\n";
			player.changeHealth(-1);
            gameBoard[y][x].type = Field::EMPTY;
		}else {
			std::cout << "You found a monster, but it was sleeping!\n";
            gameBoard[y][x].type = Field::EMPTY;
		}
	}else if (gameBoard[y][x].type == Field::WELL) {
        std::cout << "You found a well!\n";
        player.changeHealth(1);
        gameBoard[y][x].type = Field::EMPTY;
    }else {
        std::cout << "You found nothing!\n";
    }

}
int Board::getRelicAmount() {
	return relicAmount;
}