/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the Managers
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room,  and examine the items in it.
 **************************************************************/

#include <iostream>
#include "Managers.hpp"

/**************************************************************
 * 						Managers::Managers()
 * 	Description: This sets the value of the room to not being
 * 	searched. In addition it also sets the door to be locked.
 **************************************************************/
Managers::Managers() {
	setLock(true);
	searched = false;

}

/**************************************************************
 * 						Managers::roomDescription()
 * 	Description: This prints out the description of the room.
 **************************************************************/
void Managers::roomDescription() {
	if (searched) {
		std::cout << "You pass the sign labeled \"Managers Office\" again. Papers now scattered" << std::endl;
		std::cout << "about.  You didn't do a good job covering your trail, did ya...?" << std::endl;
	}
	else {
		std::cout << "You walk past a door labeled \"Managers Office\". You see papers neatly stacked." << std::endl;
		std::cout << "Maybe the manager left something important in here" << std::endl;
	}
}

/**************************************************************
 * 						Managers::examine()
 * 	Description: This method allows us to search the room for
 * 	objects.  In this room we allow the user to find the
 * 	main item, the vault key.
 **************************************************************/
void Managers::examine(Robber* burglar, Cops* police) {
	if (searched) {
		std::cout << "You find nothing of interest except some basic paperwork" << std::endl;
	}
	else {
		std::cout << "After sifting through the drawers you find a key labeled \"VAULT\"." << std::endl;
		std::cout << "Looks like you scored big buddy, good job." << std::endl;
		searched = true;
		burglar->setVaultKey();
	}
}
