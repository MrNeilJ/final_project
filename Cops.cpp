/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the Cops Class.
 * In here we create a Cop object that randomly checks to see if
 * someone has triggered it.  From there it will begin to count
 * down until it is at 0. The user loses if the cops # of rounds
 * hits 0.
 **************************************************************/

#include "Cops.hpp"
#include <memory>
#include <iostream>

/**************************************************************
 * 						Cops::Cops()
 * 	Description: This is the constructor for the Cops Class.
 * 	It'll set the trigger values, total number of rounds once
 * 	triggered, and if the cops have been called.
 **************************************************************/
Cops::Cops() {
	triggerChance = 0;
	roundsTilCaught = 10;
	copsCalled = false;
}

/**************************************************************
 * 						Cops::chanceIncrease()
 * 	Description: This method allows us to increase the liklihood
 * 	of the cops being called. Each time it is run it randomly
 * 	rolls, creating a chance of the class being triggered.
 **************************************************************/
void Cops::chanceIncrease(int chance) {
	int randNum = (rand() % 100) + 1;
	triggerChance += chance;

	// Trigger one set of chances
	if (randNum < triggerChance) {
		copsCalled = true;
		std::cout << "You hear sirens wailing in the distance, looks like you've been caught bud..." << std::endl;
		std::cout << "Grab what you can and get out ASAP!\n" << std::endl;
	}
}

/**************************************************************
 * 						Cops::getRoundsTilCaught()
 * 	Description: Returns the total number of rounds that the
 * 	Cop has remaining.
 **************************************************************/
int Cops::getRoundsTilCaught() {
	return roundsTilCaught;
}

/**************************************************************
 * 						Cops::roundSubtract()
 * 	Description: This will subtract one from the round each
 * 	time that it is called (used mainly for lock pick fails).
 **************************************************************/
void Cops::roundSubtract() {
	roundsTilCaught --;
}

/**************************************************************
 * 						Cops::wereCopsCalled()
 * 	Description: This returns a boolean value allowing us to know
 * 	if the cops were triggered or not.
 **************************************************************/
bool Cops::wereCopsCalled() {
	return copsCalled;
}
