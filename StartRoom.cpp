/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header file for the Start
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room.
 **************************************************************/

#include "StartRoom.hpp"

/**************************************************************
 * 						StartRoom::moveMenu()
 * 	Description: This forces the user to move only to the east.
 * 	It overrides the original moveMenu option created in the base
 * 	Room class.
 **************************************************************/
int StartRoom::moveMenu() {
	return 3;
}

/**************************************************************
 * 						StartRoom::roomDescription()
 * 	Description: This prints out the description of the room.
 **************************************************************/
void StartRoom::roomDescription() {
// Begin by laying out the theme
	std::cout << "It was a dark stormy night, the heavy sound of rain masks your steps as you approach." << std::endl;
	std::cout << "You look up and see the dimly light sign showing \"Bank of the Code\"." << std::endl;
}

/**************************************************************
 * 						StartRoom::examine()
 * 	Description: This method allows us to search the room for
 * 	objects.  Since this is the entry way it'll print out information
 * 	about the outside of the bank.
 **************************************************************/
void StartRoom::examine(Robber *burglar, Cops *police) {
	std::cout << "You look around cautiously, the coast is clear. Come on man, get inside already!\n" << std::endl;
}
