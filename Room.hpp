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
	Room(bool);	// Constructor
	~Room();							// Deconstructor

	bool getRoom(int direction); 	// Returns if the room in that direction is valid
	virtual Room* moveRoom(int direction, int &numPicks, Room* currentRoom);	// Returns the pointer of the room in that direction

	virtual int examine();			// Searches the room for valuables (varies per room type)
	virtual void enterRoom(int direction, int &numPicks);		// Triggers a menu that is dependent on door lock status
	virtual void roomDescription();	// Prints to the screen information about the room

	// SETTERS
	void setCoords(Room* up, Room* down, Room* right, Room* left);
	void setNorth (Room* up);
	void setSouth (Room* down);
	void setEast  (Room* right);
	void setWest  (Room* left);
	void setLock  (bool status);

	// GETTERS
	bool getLock  ();

};



#endif //FINAL_PROJECT_ROOM_HPP
