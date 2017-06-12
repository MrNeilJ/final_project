//
// Created by Neil on 6/11/2017.
//

#include "FrontRoom.hpp"

FrontRoom::FrontRoom() {
	setLock(true);
	searched = false;
}

void FrontRoom::roomDescription() {
	if (searched){
		std::cout << "You enter the front room again, the pens are in the same position. Escape once";
		std::cout << "again is within your grasp.\n" << std::endl;
	}
	else {
		std::cout << "You pass multiple desks, some with pens attached to the desk.  Directly behind";
		std::cout << " you see the door you recently cracked, escape is within your grasp.\n" << std::endl;
	}
}

void FrontRoom::examine(Robber *burglar, Cops *police) {
	menuMaker escapeChoice("Would you like to leave?", "Yes", "No");
	do {
		escapeChoice.prompt();
		if (escapeChoice.getResponse() == 1) {
			burglar->setTimetoLeave(true);
		}

	} while (escapeChoice.getResponse() < 1 && escapeChoice.getResponse() > 2);
}
