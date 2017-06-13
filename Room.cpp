/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the
 * Room Class.  In this section we provide the information
 * necessary to build the room.  We can set the coordinates of
 * the nearby rooms, as well as create the ability for the user
 * to switch room to room.
 **************************************************************/
#include <iostream>
#include "Room.hpp"

/**************************************************************
 * 						Room::Room()
 * 	Description: This is one of the constructors for the room
 * 	class.
 **************************************************************/
Room::Room(bool status) {
	// Sets the locations of the connecting rooms
	North 		= nullptr;
	South 		= nullptr;
	East  		= nullptr;
	West  		= nullptr;

	lock 		= status;
	foundKey 	= false;
}

/**************************************************************
 * 						Room::Room()
 * 	Description: This is one of the constructors for the room
 * 	class.
 **************************************************************/
Room::Room() {
	// Sets the locations of the connecting rooms
	North 		= nullptr;
	South 		= nullptr;
	East  		= nullptr;
	West  		= nullptr;

	foundKey 	= false;
	lock 		= false;
	timeToLeave	= false;
}

/**************************************************************
 * 						Room::Room()
 * 	Description: Deconstructor for the Room class. This will
 * 	set that specifics room value to all nullptrs.
 **************************************************************/
Room::~Room() {
	North = nullptr;
	South = nullptr;
	East  = nullptr;
	West  = nullptr;

}

/**************************************************************
 * 						Room::getRoom()
 * 	Description: This method checks to see if the room in a
 * 	specific direction is a valid room, or if it is pointing to
 * 	nothing (such as a wall).
 **************************************************************/
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

/**************************************************************
 * 						Room::moveRoom()
 * 	Description: This creates the movement ability in the Room
 * 	class.  It checks to see if the room is an official room.
 * 	If it is, it will check to see if that door is locked.  If it
 * 	is locked it will go through the lock mini game.  If it isn't
 * 	then the pointer value for the next room will be returned.
 **************************************************************/
Room* Room::moveRoom(int direction, Robber* burglar, Room* currentRoom, Cops* police) {
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
		std::cout << "You approach the door and jiggle the handle, the door is locked...\n" << std::endl;
		do {
			doorChoice.prompt();
			doorDecision = doorChoice.getResponse();

			// User chose to try to pick the door lock
			if (doorDecision == 1) {
				// Check to see if you have any available picks
				if (burglar->getNumPicks() > 0) {
					// roll a random # between 1 and 100
					int randNum = (rand() & 100) + 1;
					// 70% success chance on picking the door lock
					if (randNum > 45) {
						std::cout << "You hear the last tumbler click in place, the door opens.\n" << std::endl;
						tempDir->setLock(false);
						police->chanceIncrease(2);
						return tempDir;
					}
					else {
						std::cout << "Your pick snaps in half, the sound echoes down the hall." << std::endl;
						police->chanceIncrease(5);
						burglar->subtractNumPicks();
					}
				}
				else {
					std::cout << "You do not have any picks, you cannot enter this room" << std::endl;
				}
			}
			else if (doorDecision == 2) {
				std::cout << "You turn around and go back the way you came\n" << std::endl;
				return currentRoom;
			}
			else {
				std::cout << "Seriously? How did you get in here? Try again.\n" << std::endl;
			}

			if (burglar->getNumPicks() == 0) {
				std::cout << "That was your last pick...\n" << std::endl;
			}
		} while (tempDir->getLock());
	}
	else {
		return tempDir;
	}
	return currentRoom;
}

/*
void Room::enterRoom(int direction, int &numPicks) {
	menuMaker doorChoice(	"What would you like to do?",
							"Pick Lock", "Go back the way you came");
	// Check to see if the door is locked
	if (getLock()) {
		std::cout << "You approach the door and jiggle the handle, the door is locked" << std::endl;

	}

}
*/

// SETTERS
/**************************************************************
 * 						Room::setNorth()
 * 	Description: Sets the North pointer value for the room.
 **************************************************************/
void Room::setNorth(Room *up) {
	North = up;
}

/**************************************************************
 * 						Room::setSouth()
 * 	Description: Sets the South pointer value for the room.
 **************************************************************/
void Room::setSouth(Room *down) {
	South = down;
}

/**************************************************************
 * 						Room::setEast()
 * 	Description: Sets the East pointer value for the room.
 **************************************************************/
void Room::setEast(Room *right) {
	East = right;
}

/**************************************************************
 * 						Room::setWest()
 * 	Description: Sets the West pointer value for the room.
 **************************************************************/
void Room::setWest(Room *left) {
	West = left;
}

/**************************************************************
 * 						Room::setLock()
 * 	Description: Sets the Lock value to either locked or not.
 **************************************************************/
void Room::setLock(bool status) {
	lock = status;
}

/**************************************************************
 * 						Room::setCoords()
 * 	Description: Sets all the Direction Pointers at once
 **************************************************************/
void Room::setCoords(Room *up, Room *down, Room *right, Room *left) {
	North = up;
	South = down;
	East = right;
	West = left;
}

/**************************************************************
 * 						Room::setFoundKey()
 * 	Description: Sets the value of if the user has found the
 * 	key or not.
 **************************************************************/
void Room::setFoundKey(bool status) {
	foundKey = status;
}

/**************************************************************
 * 						Room::setTimeToLeave()
 * 	Description: Sets if the user has selected to leave the game
 **************************************************************/
void Room::setTimeToLeave(bool status) {
	timeToLeave = status;
}


// GETTERS
/**************************************************************
 * 						Room::getLock()
 * 	Description: Returns the lock value.
 **************************************************************/
bool Room::getLock() {
	return lock;
}

/**************************************************************
 * 						Room::getFoundKey()
 * 	Description: Returns if the user has found the key or not
 **************************************************************/
bool Room::getFoundKey() {
	return foundKey;
}

/**************************************************************
 * 						Room::getTimeToLeave()
 * 	Description: Returns if the user has found decided to leave.
 **************************************************************/
bool Room::getTimeToLeave() {
	return timeToLeave;
}

/**************************************************************
 * 						Room::moveMenu()
 * 	Description: Prints out an easy to understand menu for
 * 	how to navigate through the rooms.
 **************************************************************/
int Room::moveMenu() {
	menuMaker moveMenu("Which direction would you like to go?",
					   "North", "South", "East", "West");

	do {
		moveMenu.prompt();
		if (moveMenu.getResponse() == 1 ||
				moveMenu.getResponse() == 2 ||
				moveMenu.getResponse() == 3 ||
				moveMenu.getResponse() == 4) {
			return moveMenu.getResponse();
		}
		else {
			std::cout << "Did not catch that response, try again";
		}
	} while(moveMenu.getResponse() < 1 || moveMenu.getResponse() > 4);
}






