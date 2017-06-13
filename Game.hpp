/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header file for the
 * Game Class.  This builds 90% of the functionality of the application
 * In here we build all of the rooms, connect them together, and
 * begin the game process.
 **************************************************************/

#ifndef FINAL_PROJECT_GAME_HPP
#define FINAL_PROJECT_GAME_HPP


#include "Robber.hpp"
#include "Room.hpp"
#include "Cops.hpp"
#include "EmptyRoom.hpp"
#include "Managers.hpp"
#include "Windowed.hpp"
#include "Vault.hpp"
#include "StartRoom.hpp"
#include "FrontRoom.hpp"

class Game {
private:
	Robber* burglar;
	Cops* police;

	StartRoom* startRoom;
	FrontRoom* frontDoor;
	EmptyRoom* room1;
	EmptyRoom* room2;
	EmptyRoom* room3;
	EmptyRoom* room4;
	Managers* managers;
	EmptyRoom* room5;
	Windowed* window;
	EmptyRoom* room6;
	EmptyRoom* room7;
	EmptyRoom* room8;
	Vault* vault;

	Room* currRoom;
	bool readyToLeave;

public:
	Game();			// Constructor
	~Game();		// Destructor
	void start();	// Begins the Game play
};


#endif //FINAL_PROJECT_GAME_HPP
