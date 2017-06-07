//
// Created by Neil on 6/6/2017.
//

#ifndef FINAL_PROJECT_GAME_HPP
#define FINAL_PROJECT_GAME_HPP


#include "Room.hpp"
#include "Robber.hpp"

class Game {
private:
	Room* startRoom;
	Room* frontDoor;
	Room* room1;
	Room* room2;
	Room* room3;
	Room* room4;
	Room* managers;
	Room* room5;
	Room* window;
	Room* room6;
	Room* room7;
	Room* room8;
	Room* vault;

	Robber* burglar;

	bool readyToLeave;

public:
	Game();
	~Game();
	void start();
};


#endif //FINAL_PROJECT_GAME_HPP
