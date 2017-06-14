/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header for the Robber Class.
 * In here we allow the user to add money, add and remove picks
 * and retrieve the status of multiple items that they may have.
 **************************************************************/

#ifndef FINAL_PROJECT_ROBBER_HPP
#define FINAL_PROJECT_ROBBER_HPP
#include "menuMaker.hpp"
#include "Pick.hpp"
#include <iostream>
#include <vector>


class Robber {
private:
	std::vector<Pick>backpack; // Vector to hold lock picks
	bool  	vaultKey;	// Boolean value to check if the Robber has the main key
	int		money;		// Integer value to store the money the robber makes.
	bool	timeToLeave;
public:
	Robber();

	void addMoney(int);
	void setVaultKey();
	bool getVaultKey();
	int getNumPicks();
	void subtractNumPicks();
	int getMoney();

	bool getTimeToLeave();
	void setTimetoLeave(bool);
	void addPicks(int);
};


#endif //FINAL_PROJECT_ROBBER_HPP
