/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the Front
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room, examine the items in it, and
 * even triggers potential cop events.
 **************************************************************/
#include "FrontRoom.hpp"



/**************************************************************
 * 						FrontRoom::FrontRoom()
 * 	Description: This sets the value of the room to not being
 * 	searched. In addition it also sets the door to be locked.
 **************************************************************/
FrontRoom::FrontRoom() {
	setLock(true);
	searched = false;
}

/**************************************************************
 * 						FrontRoom::roomDescription()
 * 	Description: This prints out the description of the room.
 **************************************************************/
void FrontRoom::roomDescription() {
	if (searched){
		std::cout << "You enter the front room again, the pens are in the same position. Escape once";
		std::cout << "again is within your grasp." << std::endl;
	}
	else {
		std::cout << "You pass multiple desks, some with pens attached to the desk.  Directly behind";
		std::cout << " you see the door you recently cracked, escape is within your grasp." << std::endl;
	}
}


/**************************************************************
 * 						FrontRoom::examine()
 * 	Description: This method allows us to search the room for
 * 	objects.  Since the room is the front room, it'll allow the
 * 	user to decide if they are ready to leave or not.
 **************************************************************/
void FrontRoom::examine(Robber *burglar, Cops *police) {
	menuMaker escapeChoice("Would you like to leave?", "Yes", "No");
	do {
		escapeChoice.prompt();
		if (escapeChoice.getResponse() == 1) {
			burglar->setTimetoLeave(true);
		}

	} while (escapeChoice.getResponse() < 1 && escapeChoice.getResponse() > 2);
}
