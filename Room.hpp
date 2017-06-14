/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header file for the
 * Room Class.  In this section we provide the information
 * necessary to build the room.  We can set the coordinates of
 * the nearby rooms, as well as create the ability for the user
 * to switch room to room.
 **************************************************************/

#ifndef FINAL_PROJECT_ROOM_HPP
#define FINAL_PROJECT_ROOM_HPP


#include "Cops.hpp"
#include "Robber.hpp"

class Room {
private:
	Room* North; 	// Stores a pointer for the Northern room
	Room* South;	// Stores a pointer for the Southern room
	Room* East;		// Stores a pointer for the Eastern room
	Room* West;		// Stores a pointer for the Western room
	bool  lock;		// Stores a boolean value tracking if the door is locked
	bool  foundKey; // Stores if a key was found in that specific room
	bool  timeToLeave;
public:
	Room();			// Constructor
	Room(bool);		// Constructor
	~Room();		// Deconstructor

	bool getRoom(int direction); 	// Returns if the room in that direction is valid
	virtual Room* moveRoom(int direction, Robber* burglar, Room* currentRoom, Cops* police);	// Returns the pointer of the room in that direction

	virtual void examine(Robber*, Cops*) = 0;					// Searches the room for valuables (varies per room type)
	// virtual void enterRoom(int direction, int &numPicks);	// Triggers a menu that is dependent on door lock status
	virtual void roomDescription() = 0;							// Prints to the screen information about the room

	// SETTERS
	void setCoords(Room* up, Room* down, Room* right, Room* left); // Sets all pointers
	void setNorth (Room* up);		// Sets North Pointer
	void setSouth (Room* down);		// Sets South Pointer
	void setEast  (Room* right);    // Sets East Pointer
	void setWest  (Room* left);     // Sets West Pointer
	void setLock  (bool status);    // Sets Lock Status

	void setFoundKey (bool status);		// Sets Key status
	void setTimeToLeave(bool status);	// Sets if the user has decided to quit
	virtual int moveMenu();				// Prints out an easy to navigate menu for movement

	// GETTERS
	bool getLock();			// Returns the status of the lock
	bool getFoundKey();		// Returns the status of the key

	bool getTimeToLeave();	// Returns if the user has decided to quit

	// CLEANERS
	void cleanDirections();	// Deletes all pointers
	};

#endif //FINAL_PROJECT_ROOM_HPP
