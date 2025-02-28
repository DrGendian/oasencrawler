#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Enemy.h"
Game::Game() {
	input = ' ';
}

void Game::startGame() {
	Player player = Player();
	Enemy enemy = Enemy();
	Board gameBoard = Board();
	//gameBoard.setRelics();
	gameBoard.refreshEnemyPosition(enemy);
	gameBoard.refreshPlayerPosition(player);
	gameBoard.generateBoard();
	gameBoard.printBoard();
	player.printStats();
	std::cout << "Meow\n";
	char input = 'c';
	int health = 5;  
	int relicAmount = gameBoard.getRelicAmount();
	int relics = player.getRelics();
	while (1) {
		input = getInput(player);
		enemy.changePosition();
		system("cls");
		//Console cleared
		gameBoard.refreshEnemyPosition(enemy);
		gameBoard.checkField(player);
		gameBoard.refreshPlayerPosition(player);
		gameBoard.printBoard();
		player.printStats();
		enemy.printEnemy();
		health = player.getHealth();
		relics = player.getRelics();
		std::cout << "Relic Amount: " << relicAmount << std::endl;
		if (input == 'x' || health <= 0) {
			break;
		}
		else if (relics == relicAmount) {
			gameBoard.generateBoard();
			relicAmount = gameBoard.getRelicAmount();
			gameBoard.refreshEnemyPosition(enemy);
			gameBoard.refreshPlayerPosition(player);
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