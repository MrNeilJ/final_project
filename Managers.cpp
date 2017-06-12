//
// Created by Neil on 6/7/2017.
//

#include <iostream>
#include "Managers.hpp"

Managers::Managers() {
	setLock(true);
	searched = false;

}

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

void Managers::examine(Robber* burglar, Cops* police) {
	if (searched) {
		std::cout << "You find nothing of interest except some basic paperwork" << std::endl;
	}
	else {
		std::cout << "After sifting through the drawers you find a key labeled \"VAULT\"." << std::endl;
		std::cout << "Looks like you scored big buddy, good job." << std::endl;
		searched = true;
		burglar->setVaultKey();
		// NEED TO FIND A WAY TO GET THIS TO MODIFY THE ROBBER VALUE
	}
}
