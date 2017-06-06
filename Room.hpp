//
// Created by Neil on 6/6/2017.
//

#ifndef FINAL_PROJECT_ROOM_HPP
#define FINAL_PROJECT_ROOM_HPP


class Room {
private:
	Room* North; 	// Stores a pointer for the Northern room
	Room* South;	// Stores a pointer for the Southern room
	Room* East;		// Stores a pointer for the Eastern room
	Room* West;		// Stores a pointer for the Western room
	bool  lock;		// Stores a boolean value tracking if the door is locked
public:
	bool getRoom(int direction); 	// Returns if the room in that direction is valid
	Room* moveRoom(int direction);	// Returns the pointer of the room in that direction

	virtual int examine();			// Searches the room for valuables (varies per room type)
	virtual void enterRoom();		// Triggers a menu that is dependent on door lock status
	virtual void roomDescription();	// Prints to the screen information about the room

};



#endif //FINAL_PROJECT_ROOM_HPP
