//
// Created by Neil on 6/6/2017.
//

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
	/*void move();
	void startMove();
	bool leave();*/


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
