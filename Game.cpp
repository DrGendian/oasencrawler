#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"
Game::Game() {
	input = "";
}

void Game::startGame() {
	Player player = Player();
	Board gameBoard = Board();
	gameBoard.printBoard();
	std::cout << "Meow\n";
	int health = player.getHealth();
	
}

char Game::getInput() {
	//std::cin >> input;

	return 'c';
}

void printStats() {

}
