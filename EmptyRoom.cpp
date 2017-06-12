//
// Created by Neil on 6/7/2017.
//

#include <iostream>
#include "EmptyRoom.hpp"

void EmptyRoom::roomDescription() {
	std::cout << 	"You enter the room and look around, there appears to be nothing\n"
			  << 	" of interest in here." << std::endl;
}

void EmptyRoom::examine(Robber* burglar, Cops* police) {
	int randNum = (rand() % 10000) + 1;
	int copChance = (rand() % 10) + 1;

	if (searched) {
		std::cout << "You have already searched this room, there isn't anything left!" << std::endl;
	}

	else if (randNum > 7000) {
		int randPicks = (rand() + 5) + 1;
		std::cout << "You pull the potted plant out, finding a time capsule," << std::endl;
		std::cout << "it contained " << randPicks<< "Lock Picks! How Weird!" << std::endl;

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
		std::cout << "contained " << randNum << "dollars, dang! " << std::endl;

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

EmptyRoom::EmptyRoom() {
	searched = false;

}



