//
// Created by Neil on 6/7/2017.
//

#include <iostream>
#include "EmptyRoom.hpp"

void EmptyRoom::roomDescription() {
	std::cout << 	"You enter the room and look around, there appears to be nothing\n"
			  << 	" of interest in here." << std::endl;
}

int EmptyRoom::examine(Cops* police) {
	int randNum = (rand() % 10000) + 1;
	int copChance = (rand() % 10) + 1;

	if (searched) {
		std::cout << "You have already searched this room, there isn't anything left!" << std::endl;
	}
	else if (randNum > 9000) {
		std::cout << "You pushed a painting to the side and found a secret safe," << std::endl;
		std::cout << "containing " << randNum << " dollars, awesome!" << std::endl;

		if (copChance > 5) {
			std::cout << "You immediately drop the painting, hopefully no one heard that" << std::endl;
			// ADD IN POLICE FUNCTIONALITY LATER
		}
		searched = true;
		return randNum;
	}
	else if (randNum > 8000) {
		std::cout << "You pull the potted plant out, finding a time capsule," << std::endl;
		std::cout << "it contained " << randNum << "dollars, good job!" << std::endl;

		if (copChance > 5) {
			std::cout << "As you put the plant back the vase shatters, the sound" << std::endl;
			std::cout << "echoes down the hallway." << std::endl;
			// ADD IN POLICE FUNCTIONALITY LATER
		}
		searched = true;
		return randNum;
	}
	else if (randNum > 6000) {
		std::cout << "You pull open a drawer, finding someones wallet, it" << std::endl;
		std::cout << "contained " << randNum << "dollars, dang! " << std::endl;

		if (copChance > 7) {
			std::cout << "You pull the drawer open too far, it crashes to the floor." << std::endl;
			std::cout << "Not too get at being quiet are ya...?" << std::endl;
			// ADD IN POLICE FUNCTIONALITY LATER
		}
		searched = true;
		return  randNum;
	}
	else if (randNum > 5000) {
		std::cout << "You see something shining underneath a desk, upon examination" << std::endl;
		std::cout << "it appears to be a diamond, probably worth " << randNum << " dollars!" << std::endl;
		searched = true;
		return randNum;
	}
	else {
		std::cout << "You search the room, but find nothing of interest..." << std::endl;
		searched = true;
		return 0;
	}

	return 0;

}

EmptyRoom::EmptyRoom() {
	searched = false;

}



