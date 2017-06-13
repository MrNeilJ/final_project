/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the Window
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room, examine the items in it, and
 * even triggers events that allow the user to leave.
 **************************************************************/

#include <iostream>
#include "Windowed.hpp"

/**************************************************************
 * 						Windowed::Windowed()
 * 	Description: This sets the value of the room to not being
 * 	searched. Also sets the lock value to true.
 **************************************************************/
Windowed::Windowed() {
	searched = false;
	setLock(true);
}

/**************************************************************
 * 						Windowed::roomDescription()
 * 	Description: This prints out the description of the room.
 **************************************************************/
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

/**************************************************************
 * 						Windowed::examine()
 * 	Description: This method allows us to search the room for
 * 	objects.  In this the user finds an escape route. They are
 * 	then given the option if they would like to escape.
 **************************************************************/
void Windowed::examine(Robber* burglar, Cops* police) {
	int randNum = (rand() % 6) + 1;

	if(!searched){
		std::cout << "You search through the closet and find" << randNum << " lock picks" << std::endl;
		std::cout << "You then look up and find an open window, you could probably fit, but you" << std::endl;
		std::cout << "be able to take much with you...easy escape though." << std::endl;
		searched = true;
	}

	menuMaker escapeOption("Do you want to escape now?", "Yes", "No");
	int escapeChoice;

	do {
		escapeOption.prompt();
		escapeChoice = escapeOption.getResponse();

		if (escapeChoice == 1) {
			menuMaker areYouSure("Are you sure? You'll lose half your money squeezing out this window!",
								"Yes, lets go already!", "No, we will find another way");
			areYouSure.prompt();
			if(areYouSure.getResponse() == 1) {
				burglar->setTimetoLeave(true);
			}

		}
	} while(escapeChoice < 1 && escapeChoice > 2);

}
