/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation for the Robber Class.
 * In here we allow the user to add money, add and remove picks
 * and retrieve the status of multiple items that they may have.
 **************************************************************/

#include "Robber.hpp"


/**************************************************************
 * 						Robber::Robber()
 * 	Description: Constructor for the Robber class
 **************************************************************/
Robber::Robber() {
	addPicks(10);
	vaultKey = false;
	timeToLeave = false;
	money = 0;
}

/**************************************************************
 * 						Robber::addMoney()
 * 	Description: Adds money to the money integer
 **************************************************************/
void Robber::addMoney(int input) {
	money += input;
}

/**************************************************************
 * 						Robber::setVaultKey()
 * 	Description: Sets the ownership of the vault key to either
 * 	true or false
 **************************************************************/
void Robber::setVaultKey() {
	vaultKey = true;
}

/**************************************************************
 * 						Robber::getNumPicks()
 * 	Description: returns the number of Picks in the backpack
 **************************************************************/
int Robber::getNumPicks() {
	return backpack.size();
}

/**************************************************************
 * 						Robber::subtractNumPicks()
 * 	Description: removes one pick from the bag
 **************************************************************/
void Robber::subtractNumPicks() {
	// get size of vector
	backpack.pop_back();
}

/**************************************************************
 * 						Robber::getVaultKey()
 * 	Description: Returns if the use has the key or not
 **************************************************************/
bool Robber::getVaultKey() {
	return vaultKey;
}

/**************************************************************
 * 						Robber::getMoney()
 * 	Description: returns the value stored in the money variable
 **************************************************************/
int Robber::getMoney() {
	return money;
}

/**************************************************************
 * 						Robber::getTimeToLeave()
 * 	Description: returns the value stored in timeToLeave
 **************************************************************/
bool Robber::getTimeToLeave() {
	return timeToLeave;
}

/**************************************************************
 * 						Robber::setTimeToLeave()
 * 	Description: Modifies the value stored in timeToLeave
 **************************************************************/
void Robber::setTimetoLeave(bool status) {
	timeToLeave = status;
}

/**************************************************************
 * 						Robber::addPicks()
 * 	Description: add picks to the backpack, if it is more than
 * 	10 it will stop the user from adding picks.
 **************************************************************/
void Robber::addPicks(int amount) {
	Pick tempPick = Pick();
	int tempAmt = amount;
	for(int i = 0; i < amount && backpack.size() < 10; i++){
		backpack.push_back(tempPick);
		tempAmt--;
	}
	if (tempAmt > 0) {
		std::cout << "\nYour bag is full, you had to leave " << tempAmt << " behind.\n" << std::endl;
	}

}



