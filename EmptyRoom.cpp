/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the Empty
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room, examine the items in it, and
 * even triggers potential cop events.
 **************************************************************/

#include <iostream>
#include "EmptyRoom.hpp"

/**************************************************************
 * 						EmptyRoom::roomDescription()
 * 	Description: This prints out the description of the room.
 **************************************************************/
void EmptyRoom::roomDescription() {
	std::cout << 	"You enter the room and look around, there appears to be nothing\n"
			  << 	" of interest in here." << std::endl;
}

/**************************************************************
 * 						EmptyRoom::examine()
 * 	Description: This method allows us to search the room for
 * 	objects.  Since the room is empty the chance of items in here
 * 	are fairly slim.  The user can come across random bits of
 * 	cash and lock picks in these rooms though.
 **************************************************************/
void EmptyRoom::examine(Robber* burglar, Cops* police) {
	int randNum = (rand() % 10000) + 1;
	int copChance = (rand() % 10) + 1;

	if (searched) {
		std::cout << "You have already searched this room, there isn't anything left!" << std::endl;
	}

	else if (randNum > 7000) {
		int randPicks = (rand() % 5) + 1;
		std::cout << "You pull the potted plant out, finding a time capsule," << std::endl;
		std::cout << "it contained " << randPicks<< " Lock Picks! How Weird!" << std::endl;

		burglar->addPicks(randPicks);

		if (copChance > 5) {
			std::cout << "As you put the plant back the vase shatters, the sound" << std::endl;
			std::cout << "echoes down the hallway." << std::endl;
			// ADD IN POLICE FUNCTIONALITY LATER
			police->chanceIncrease(5);
		}
		searched = true;
		burglar->addMoney(randNum);
	}
	else if (randNum > 6000) {
		std::cout << "You pull open a drawer, finding someones wallet, it" << std::endl;
		std::cout << "contained " << randNum << " dollars, dang! " << std::endl;

		if (copChance > 7) {
			std::cout << "You pull the drawer open too far, it crashes to the floor." << std::endl;
			std::cout << "Not too get at being quiet are ya...?" << std::endl;
			// ADD IN POLICE FUNCTIONALITY LATER
			police->chanceIncrease(5);
		}
		searched = true;
		burglar->addMoney(randNum);
	}
	else if (randNum > 5000) {
		std::cout << "You see something shining underneath a desk, upon examination" << std::endl;
		std::cout << "it appears to be a diamond, probably worth " << randNum << " dollars!" << std::endl;
		searched = true;
		burglar->addMoney(randNum);
	}
	else {
		std::cout << "You search the room, but find nothing of interest..." << std::endl;
		searched = true;
		burglar->addMoney(0);
	}

}

/**************************************************************
 * 						EmptyRoom::EmptyRoom()
 * 	Description: This sets the value of the room to not being
 * 	searched. Other values do not need to be modified at this
 * 	point.
 **************************************************************/

EmptyRoom::EmptyRoom() {
	searched = false;

}
