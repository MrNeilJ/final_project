//
// Created by Neil on 6/6/2017.
//

#include "Robber.hpp"


void Robber::move() {
	// Ask the user which direction they would like to move
	menuMaker moveMenu("Which direction would you like to go?",
					   "North", "South", "East", "West");
	int direction;
	bool moved = false;
	// Loop until a valid response has been chosen
	do {
		moveMenu.prompt();
		direction = moveMenu.getResponse();
		// Make sure the user selected a value between 1 and 4
		if (direction >= 1 && direction <= 4) {
			// Check to see if the direction has a valid room
			if (!currRoom->getRoom(direction)) {
				std::cout << "You turn and face a wall, you cannot walk this direction." << std::endl;
				std::cout << "Try a different direction";
			}
			else {
				moved = true;
				currRoom = currRoom->moveRoom(direction);
			}
		}
		else {
			std::cout << "That isn't an option, come on...you worry me." << std::endl;
		}
	} while (!moved);
}


