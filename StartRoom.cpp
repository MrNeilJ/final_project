//
// Created by Neil on 6/11/2017.
//

#include <iostream>
#include "StartRoom.hpp"

int StartRoom::moveMenu() {
	return 3;
}

void StartRoom::roomDescription() {
// Begin by laying out the theme
	std::cout << "It was a dark stormy night, the heavy sound of rain masks your steps as you approach." << std::endl;
	std::cout << "You look up and see the dimly light sign showing \"Bank of the Code\"." << std::endl;
}

void StartRoom::examine(Robber *burglar, Cops *police) {
	std::cout << "You look around cautiously, the coast is clear. Come on man, get inside already!\n" << std::endl;
}
