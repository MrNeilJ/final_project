//
// Created by Neil on 6/6/2017.
//

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
	Game();
	~Game();
	void start();
};


#endif //FINAL_PROJECT_GAME_HPP
