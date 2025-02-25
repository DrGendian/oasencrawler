#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"
Game::Game() {
	input = ' ';
}

void Game::startGame() {
	Player player = Player();
	Board gameBoard = Board();
	gameBoard.printBoard();
	std::cout << "Meow\n";
	player.printStats();
}

char Game::getInput(Player player) {
	std::cout << "Enter Direction (W/A/S/D) ";
	std::cin >> input;
	switch (input) {
		case 'w':
			
			break;
		case 's':
			break;
		case 'a':
			break;
		case 'd':
			break;
		default:
			std::cout << "Wrong Input!";
	}
	return 'c';
}