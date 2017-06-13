/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the header file for the Vault
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room. In addition this is where the
 * user will find the majority of their gold.
 **************************************************************/

#ifndef FINAL_PROJECT_VAULT_HPP
#define FINAL_PROJECT_VAULT_HPP


#include "Room.hpp"

class Vault : public Room {
private:
	bool searched;					// Boolean used to save if the room has been searched 

public:
	Vault();                        // Constructor
	void roomDescription();         // Returns the rooms description information
	void examine(Robber*, Cops*);   // Allows the user to search the room for items.
};


#endif //FINAL_PROJECT_VAULT_HPP
