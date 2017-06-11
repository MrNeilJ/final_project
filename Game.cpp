//
// Created by Neil on 6/6/2017.
//

#include "Game.hpp"

Game::Game() {
// Initialize Room information
	startRoom	= new Room(false);
	frontDoor 	= new Room(true);
	room1		= new EmptyRoom();
	room2		= new EmptyRoom();
	room3		= new EmptyRoom();
	room4		= new EmptyRoom();
	managers	= new Managers();
	room5		= new EmptyRoom();
	window		= new Windowed();
	room6		= new EmptyRoom();
	room7		= new EmptyRoom();
	room8		= new EmptyRoom();
	vault		= new Vault();

// Link together the rooms to build the map
	startRoom->setEast(frontDoor);
	frontDoor->setEast(room1);
	room1->setCoords(nullptr, nullptr, room2, frontDoor);
	room2->setCoords(room3, nullptr, room4, room1);
	room3->setCoords(nullptr, room2, nullptr, nullptr);
	room4->setCoords(nullptr, managers, room5, room2);
	managers->setCoords(room4, nullptr, nullptr, nullptr);
	room5->setCoords(window, nullptr, room6, room4);
	window->setCoords(nullptr, room5, nullptr, nullptr);
	room6->setCoords(nullptr, nullptr, room7, room5);
	room7->setCoords(nullptr, room8, nullptr, room6);
	room8->setCoords(room7, vault,   nullptr, nullptr);
	vault->setCoords(room8, nullptr, nullptr, nullptr);

	burglar = new Robber();


// Set the Robbers initial location
	burglar->setLocation(startRoom);
// Set the initial readyToLeave to False;
	readyToLeave = false;
}

Game::~Game() {
	startRoom	= nullptr;
	frontDoor 	= nullptr;
	room1		= nullptr;
	room2		= nullptr;
	room3		= nullptr;
	room4		= nullptr;
	managers	= nullptr;
	room5		= nullptr;
	window		= nullptr;
	room6		= nullptr;
	room7		= nullptr;
	room8		= nullptr;
	vault		= nullptr;
}

void Game::start() {
	// Move the burglar to the front door
	burglar->startMove();

	do {
		burglar->move();


	} while (!burglar->leave());
	std::cout << "You escaped safely, no one noticed" << std::endl;

}
