/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the
 * Game Class.  This builds 90% of the functionality of the application
 * In here we build all of the rooms, connect them together, and
 * begin the game process.
 **************************************************************/

#include "Game.hpp"
#include "StartRoom.hpp"
#include "FrontRoom.hpp"

/**************************************************************
 * 						Game::Game()
 * 	Description: This is the constructor of the Game class.  It
 * 	will implement all of the room files, connect them, and
 * 	create the robber and cop classes for the game functionality.
 **************************************************************/
Game::Game() {
	burglar = new Robber();
	police = new Cops();
// Initialize Room information
	startRoom	= new StartRoom();
	frontDoor 	= new FrontRoom();
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

// Set the initial readyToLeave to False;
	readyToLeave = false;
}

/**************************************************************
 * 						Game::~Game()
 * 	Description: This is the deconstructor class, It will set
 * 	all the newly created pointers to nullptr values.
 **************************************************************/
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

	burglar 	= nullptr;
	police		= nullptr;
}

/**************************************************************
 * 						Game::Start()
 * 	Description: This is what creates the game functionality.
 * 	It Moves the user room to room, interacting with the functions
 * 	of each room.  Allowing the user to unlock doors, steal items,
 * 	and even escape when they are ready.
 **************************************************************/
void Game::start() {
	// Set the Current Room to the Start Room
	currRoom = startRoom;

	menuMaker examineOrMove("What would you like to do?",
							"Search Room",
							"Move to the next room");
	int direction;
	bool moved;
	int choice;

	// Move the user to the first locked door

	do {
		moved = false;
		std::string hasVault = "No";
		if (burglar->getVaultKey()) {
			hasVault = "Yes";
		}
		// Print out the total number of lockPicks, vaultkeys, and turns till cops come
		std::cout << "|| # of picks: " << burglar->getNumPicks() << " || Vault Key: " << hasVault;
		std::cout << " || Rounds 'til Cops arrive: " << police->getRoundsTilCaught() << " || " << std::endl;
		std::cout << "|| Total Money: " << burglar->getMoney() << "\n" << std::endl;

		// Print out the Current Rooms Description
		currRoom->roomDescription();
		std::cout <<  std::endl;
		do {

			do {
				// Allow the user to decide to either examine the room, or proceed to the next room
				examineOrMove.prompt();
				choice = examineOrMove.getResponse();

				if (choice < 1 || choice > 2) {
					std::cout << "Seriously? Pick an option and move on, we don't have time!" << std::endl;
				}
			} while(choice < 1 || choice > 2);

			if (choice == 1) {
				currRoom->examine(burglar, police);
				// Check to see if the robber found a key in that room
				if (currRoom->getFoundKey()) {
					burglar->setVaultKey();
				}
				// Check to see if the robber decided to leave the game (either through the window or main entrance)
				if (burglar->getTimeToLeave()) {
					moved = true;
				}
			}
			else if (choice == 2) {
				direction = currRoom->moveMenu();
				// Make sure the user selected a value between 1 and 4
				if (direction >= 1 && direction <= 4) {
					// Check to see if the direction has a valid room
					if (!(currRoom->getRoom(direction))) {
						std::cout << "You turn and face a wall, you cannot walk this direction." << std::endl;
						std::cout << "Try a different direction.\n" << std::endl;
					}
					else {
						moved = true;
						currRoom = currRoom->moveRoom(direction, burglar, currRoom, police);
					}
				}
				else {
					std::cout << "That isn't an option, come on...you worry me." << std::endl;
				}
			}
		} while (!moved);

		// Check to see if the cops were triggered
		if(police->wereCopsCalled()) {
			// If so, subtract 1 for each round active
			police->roundSubtract();
		}
	} while(police->getRoundsTilCaught() > 0 && !burglar->getTimeToLeave());

	if (police->getRoundsTilCaught() < 1) {
		std::cout << "Game over, the cops caught you, guess i'll have to find a new partner" << std::endl;
	}

	else if (burglar->getMoney() > 10000) {
		std::cout << "GOOD JOB MAN! You made it out safely with " << burglar->getMoney() << " dollars!" << std::endl;
	}
	else if (burglar->getMoney() > 5000) {
		std::cout << "Hey, you made it out, and at least you made it out with " << burglar->getMoney() << " dollars." << std::endl;
	}
	else {
		std::cout << "I hate you, you're fired, you only brought back " << burglar->getMoney() << " dolllars..." << std::endl;
	}
}


