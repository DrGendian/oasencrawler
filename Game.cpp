#include <iostream>
#include <vector>
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Enemy.h"
Game::Game() {
	input = ' ';
	std::vector<Enemy> enemyCount;
}

void Game::startGame() {
	Player player = Player();
	enemyCount.push_back(Enemy());
	enemyCount.push_back(Enemy());
	Board gameBoard = Board();
	//gameBoard.setRelics();
	gameBoard.generateBoard();
	for (Enemy& enemy : enemyCount) {
		gameBoard.refreshEnemyPosition(enemy, player);
	}
	gameBoard.refreshPlayerPosition(player);
	gameBoard.printBoard();
	player.printStats();
	std::cout << "Meow\n";
	char input = 'c';
	int health = 5;  
	int relicAmount = gameBoard.getRelicAmount();
	int relics = player.getRelics();
	while (1) {
		input = getInput(player);
		system("cls");
		//Console cleared
		gameBoard.checkField(player);
		gameBoard.refreshPlayerPosition(player);
		for (Enemy& enemy : enemyCount) {
			enemy.changePosition();
			gameBoard.refreshEnemyPosition(enemy, player);
		}
		gameBoard.printBoard();
		player.printStats();
		for (Enemy& enemy : enemyCount) {
			enemy.printEnemy();
		}
		health = player.getHealth();
		relics = player.getRelics();
		std::cout << "Relic Amount: " << relicAmount << std::endl;
		if (input == 'x' || health <= 0) {
			break;
		}
		else if (relics == relicAmount) {
			enemyCount.push_back(Enemy());
			gameBoard.generateBoard();
			relicAmount = gameBoard.getRelicAmount();
			for (Enemy& enemy : enemyCount) {
				gameBoard.refreshEnemyPosition(enemy, player);
			}
			gameBoard.refreshPlayerPosition(player);
			gameBoard.increaseDifficulty();
		}
	}
}

char Game::getInput(Player& player) {
	std::cout << "\nEnter Direction (W/A/S/D) ";
	std::cin >> this->input;

	switch (this->input) {
		case 'w':
			player.changePosition(-1,'y');
			break;
		case 's':
			player.changePosition(1,'y');
			break;
		case 'a':
			player.changePosition(-1,'x');
			break;
		case 'd':
			player.changePosition(1,'x');
			break;
		default:
			std::cout << "Wrong Input!\n";
	}
	return this->input;
}