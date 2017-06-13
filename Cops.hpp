/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header file for the Cops Class.
 * In here we create a Cop object that randomly checks to see if
 * someone has triggered it.  From there it will begin to count
 * down until it is at 0. The user loses if the cops # of rounds
 * hits 0.
 **************************************************************/

#ifndef FINAL_PROJECT_COPS_HPP
#define FINAL_PROJECT_COPS_HPP


class Cops {
private:
	int triggerChance;					// Value that shows the liklihood of the cops being called
	int roundsTilCaught;				// Timer value to have a chance the player will lose
	bool copsCalled;					// Boolean value that tells us if the cops have been called
public:
	Cops();								// Constructor
	void chanceIncrease(int chance);	// Increase the chance of cops being called

	int getRoundsTilCaught();           // Returns number of rounds
	void roundSubtract();               // Subtracts total number of rounds remaining
	bool wereCopsCalled();              // Returns if the cops were called
};


#endif //FINAL_PROJECT_COPS_HPP
