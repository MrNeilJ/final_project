//
// Created by Neil on 6/6/2017.
//

#include <iostream>
#include "Room.hpp"
#include "menuMaker.hpp"

Room::Room(bool status) {
	// Sets the locations of the connecting rooms
	North = nullptr;
	South = nullptr;
	East  = nullptr;
	West  = nullptr;

	lock = status;
}

Room::Room() {
	// Sets the locations of the connecting rooms
	North = nullptr;
	South = nullptr;
	East  = nullptr;
	West  = nullptr;
}

Room::~Room() {
	North = nullptr;
	South = nullptr;
	East  = nullptr;
	West  = nullptr;

}



int Room::examine() {
	return 0;
}

bool Room::getRoom(int direction) {
	bool isRoom = true;
	// Check to see if there is a room that direction
	if (direction == 1) {
		// check north
		if (North == nullptr) {
			isRoom = false;
		}
	}
	else if (direction == 2) {
		// check south
		if (South == nullptr) {
			isRoom = false;
		}
	}
	else if (direction == 3) {
		// check east
		if (East == nullptr) {
			isRoom = false;
		}
	}
	else if (direction == 4) {
		// check west
		if (West == nullptr) {
			isRoom = false;
		}
	}
	// Return true or false on if it is a room or not
	return  isRoom;
}

Room* Room::moveRoom(int direction, int &numPicks, Room* currentRoom) {
	Room* tempDir;
	int doorDecision;
	menuMaker doorChoice(	"What would you like to do?",
							 "Pick Lock", "Go back the way you came");
	if (direction == 1) {
		tempDir = North;
	}
	else if (direction == 2) {
		tempDir = South;
	}
	else if (direction == 3) {
		tempDir = East;
	}
	else {
		tempDir = West;
	}

	if (tempDir->getLock()) {
		std::cout << "You approach the door and jiggle the handle, the door is locked..." << std::endl;
		do {
			doorChoice.prompt();
			doorDecision = doorChoice.getResponse();

			// User chose to try to pick the door lock
			if (doorDecision == 1) {
				// Check to see if you have any available picks
				if (numPicks > 0) {
					// roll a random # between 1 and 100
					int randNum = (rand() & 100) + 1;
					// 70% success chance on picking the door lock
					if (randNum > 45) {
						std::cout << "You hear the last tumbler click in place, the door opens" << std::endl;
						tempDir->setLock(false);
						return tempDir;
					}
					else {
						std::cout << "Your pick snaps in half, the sound echoes down the hall." << std::endl;
						numPicks--;
					}
				}
				else {
					std::cout << "You do not have any picks, you cannot enter this room" << std::endl;
				}
			}
			else if (doorDecision == 2) {
				std::cout << "You turn around and go back the way you came" << std::endl;
				return currentRoom;
			}
			else {
				std::cout << "Seriously? How did you get in here? Try again." << std::endl;
			}

			if (numPicks == 0) {
				std::cout << "That was your last pick" << std::endl;
			}
		} while (tempDir->getLock());
	}
	else {
		return tempDir;
	}
	return currentRoom;
}

void Room::enterRoom(int direction, int &numPicks) {
	menuMaker doorChoice(	"What would you like to do?",
							"Pick Lock", "Go back the way you came");
	// Check to see if the door is locked
	if (getLock()) {
		std::cout << "You approach the door and jiggle the handle, the door is locked" << std::endl;

	}

}

void Room::roomDescription() {

}

// SETTERS
void Room::setNorth(Room *up) {
	North = up;
}

void Room::setSouth(Room *down) {
	South = down;

}

void Room::setEast(Room *right) {
	East = right;
}

void Room::setWest(Room *left) {
	West = left;
}

void Room::setLock(bool status) {
	lock = status;
}

bool Room::getLock() {
	return lock;
}

void Room::setCoords(Room *up, Room *down, Room *right, Room *left) {
	North = up;
	South = down;
	East = right;
	West = left;
}




