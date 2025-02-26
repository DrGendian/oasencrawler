#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"
Game::Game() {
	input = ' ';
	relicAmount = 5;
}

void Game::startGame() {
	Player player = Player();
	Board gameBoard = Board();
	std::cout << "Meow\n";
	char input;
	while (1) {
		gameBoard.changePlayerPosition(player);
		gameBoard.printBoard();
		player.printStats();
		input = getInput(player);
		if (input == 'x') {
			break;
		}
	}
}

char Game::getInput(Player& player) {
	std::cout << "\nEnter Direction (W/A/S/D) ";
	std::cin >> this->input;
	switch (this->input) {
		case 'w':
			player.changePosition(1,'y');
			break;
		case 's':
			player.changePosition(-1,'y');
			break;
		case 'a':
			player.changePosition(-1,'x');
			break;
		case 'd':
			player.changePosition(1,'x');
			break;
		default:
			std::cout << "Wrong Input!";
	}
	return this->input;
}