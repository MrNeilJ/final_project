//
// Created by Neil on 6/6/2017.
//

#ifndef FINAL_PROJECT_ROBBER_HPP
#define FINAL_PROJECT_ROBBER_HPP
#include "Room.hpp"
#include "menuMaker.hpp"
#include <iostream>


class Robber {
private:
	int		lockPick;	// Number of picks the robber will have
	bool  	vaultKey;	// Boolean value to check if the Robber has the main key
	Room* 	currRoom;	// Pointer to the current room the robber is in.
public:
	Robber();
	Robber(Room*);
	void move();
	void startMove();
	void setLocation(Room*);
	Room* getLocation();
};


#endif //FINAL_PROJECT_ROBBER_HPP
