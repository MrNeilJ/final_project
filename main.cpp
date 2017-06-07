#include <iostream>
#include "Room.hpp"
#include "Game.hpp"

int main() {
	// Begin by laying out the theme
	std::cout << "It was a dark stormy night, the heavy sound of rain masks your steps as you approach." << std::endl;
	std::cout << "You look up and see the dimly light sign showing \"Bank of the Code\"." << std::endl;

	Game newGame;
	newGame.start();




	return 0;
}