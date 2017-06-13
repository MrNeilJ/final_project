#include <iostream>
#include <time.h>
#include "Game.hpp"

int main() {
	srand(time(NULL));
	std::cout << "*************************************************" << std::endl;
	std::cout << "*             ULTIMATE BANK HEIST GAME          *" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "Your goal in this game is to steal as much money as possible from the bank";
	std::cout << " before the police arrive.  If you trigger the police you will have ten turns";
	std::cout << " to escape before you are arrested. Look around, find keys, steal money and";
	std::cout << " most importantly, find a way to escape!" << std::endl;



	Game newGame;
	newGame.start();




	return 0;
}