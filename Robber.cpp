//
// Created by Neil on 6/6/2017.
//

#include "Robber.hpp"


/*void Robber::move() {
	// Ask the user which direction they would like to move
	menuMaker moveMenu("Which direction would you like to go?",
					   "North", "South", "East", "West");

	menuMaker examineOrMove("What would you like to do?",
							"Search Room",
							"Move to the next room");
	int direction;
	bool moved = false;
	int choice;

	// Loop until a valid response has been chosen
	do {
		// Give the user the description of the current room
		currRoom->roomDescription();
		std::cout << std::endl;

		do {
			// Allow the user to decide to either examine the room, or proceed to the next room
			examineOrMove.prompt();
			choice = examineOrMove.getResponse();

			if (choice < 1 || choice > 2) {
				std::cout << "Seriously? Pick an option and move on, we don't have time!" << std::endl;
			}
		} while(choice < 1 || choice > 2);

		if (choice == 1) {
			addMoney(currRoom->examine());
			// Check to see if the robber found a key in that room
			if (getLocation()->getFoundKey()) {
				setVaultKey();
			}
			// Check to see if the robber decided to leave the game (either through the window or main entrance)
			if (currRoom->getTimeToLeave()) {

			}
		}
		else if (choice == 2) {
			moveMenu.prompt();
			direction = moveMenu.getResponse();
			// Make sure the user selected a value between 1 and 4
			if (direction >= 1 && direction <= 4) {
				// Check to see if the direction has a valid room
				if (!(currRoom->getRoom(direction))) {
					std::cout << "You turn and face a wall, you cannot walk this direction." << std::endl;
					std::cout << "Try a different direction" << std::endl;
				}
				else {
					moved = true;
					currRoom = currRoom->moveRoom(direction, lockPick, currRoom);
				}
			}
			else {
				std::cout << "That isn't an option, come on...you worry me." << std::endl;
			}
		}
	} while (!moved);
}*/



Robber::Robber() {
	lockPick = 10;
	vaultKey = false;
	timeToLeave = false;
	money = 0;
}


void Robber::addMoney(int input) {
	money += input;
}

void Robber::setVaultKey() {
	vaultKey = true;
}


int Robber::getNumPicks() {
	return lockPick;
}

void Robber::subtractNumPicks() {
	lockPick--;
}

bool Robber::getVaultKey() {
	return vaultKey;
}

int Robber::getMoney() {
	return money;
}

bool Robber::getTimeToLeave() {
	return timeToLeave;
}

void Robber::setTimetoLeave(bool status) {
	timeToLeave = status;
}

void Robber::addPicks(int amount) {
	lockPick+=amount;
	if (lockPick > 10) {
		std::cout << "You cannot carry that many lock picks, leave some behind" << std::endl;
		lockPick = 10;
	}
}



