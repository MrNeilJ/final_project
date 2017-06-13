/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header file for the Empty
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room, examine the items in it, and
 * even triggers potential cop events.
 **************************************************************/

#ifndef FINAL_PROJECT_EMPTYROOM_HPP
#define FINAL_PROJECT_EMPTYROOM_HPP


#include "Room.hpp"
#include "Cops.hpp"

class EmptyRoom : public Room {
private:
	bool searched;						// Boolean used to save if the room has been searched

public:
	EmptyRoom();                        // Constructor
	void roomDescription();             // Returns the rooms description information
	void examine(Robber*, Cops*);       // Allows the user to search the room for items.

};


#endif //FINAL_PROJECT_EMPTYROOM_HPP
