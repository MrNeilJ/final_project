/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header file for the Start
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room.
 **************************************************************/

#ifndef FINAL_PROJECT_STARTROOM_HPP
#define FINAL_PROJECT_STARTROOM_HPP


#include "Robber.hpp"
#include "Cops.hpp"
#include "Room.hpp"

class StartRoom : public Room{
public:
	virtual int moveMenu();							// Modifies the original Move menu
	void roomDescription();							// Prints room descriptions
	void examine(Robber* burglar, Cops* police);	// Allows the user to examine the room
};


#endif //FINAL_PROJECT_STARTROOM_HPP
