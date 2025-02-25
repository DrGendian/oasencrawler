#include <iostream>

int main()
{
    std::string board[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = "*";
        }
    }
    std::cout << "Meow\n";
        for (int i = 0; i < 5; i++) {
            std::cout << "|";
        for (int j = 0; j < 5; j++) {
            std::cout << " " << board[i][j];
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}