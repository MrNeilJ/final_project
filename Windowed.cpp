//
// Created by Neil on 6/7/2017.
//

#include <iostream>
#include "Windowed.hpp"
#include "menuMaker.hpp"

Windowed::Windowed() {
	searched = false;
	setLock(true);
}

void Windowed::roomDescription() {
	if (searched) {
		std::cout << "You enter the Janitors Closet again. You feel the breeze of the open window." << std::endl;
		std::cout << "Easy opportunity to call it quits if you want..." << std::endl;
	}
	else {
		std::cout << "You enter the room, you see brooms in the corner, looking up you see" << std::endl;
		std::cout << "a window at the end of the room." << std::endl;
	}
}

int Windowed::examine() {
	searched = true;
	int randNum = (rand() % 500) + 1;

	std::cout << "You search through the closet and find" << randNum << " dollars" << std::endl;
	std::cout << "You then look up and find an open window, you could probably fit, but you" << std::endl;
	std::cout << "be able to take much with you...easy escape though." << std::endl;

	menuMaker escapeOption("Do you want to escape now?", "Yes", "No");
	int escapeChoice;

	do {
		escapeOption.prompt();
		escapeChoice = escapeOption.getResponse();

		if (escapeChoice == 1) {
			setTimeToLeave(true);
		}
	} while(escapeChoice < 1 || escapeChoice > 2);

}
