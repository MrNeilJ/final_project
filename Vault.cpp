/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 6.13.2017
 *
 * Description: This is the implementation file for the Vault
 * Room Class.  In this section we provide the information
 * necessary to build the room.  It allows us to print the
 * descriptions of the room. In addition this is where the
 * user will find the majority of their gold.
 **************************************************************/

#include <iostream>
#include "Vault.hpp"

/**************************************************************
 * 						Vault::Vault()
 * 	Description: This sets the value of the room to not being
 * 	searched. Also sets the lock value to "locked"
 **************************************************************/
Vault::Vault() {
	searched = false;
	setLock(true);
}

/**************************************************************
 * 						Vault::roomDescription()
 * 	Description: This prints out the description of the room.
 **************************************************************/
void Vault::roomDescription() {
		std::cout << "You open the door, and see the large silver shielded door, you attempt to push " << std::endl;
		std::cout << "it open, but it won't budge. Maybe we should use a key" << std::endl;

}

/**************************************************************
 * 						Vault::examine()
 * 	Description: This method allows us to search the room for
 * 	objects.  This room has the most valuable objects.  Some of
 * 	the objects have th chance of triggering cops arrival.
 **************************************************************/
void Vault::examine(Robber* burglar, Cops* police) {
	menuMaker vaultOptions(	"What would you like to do?",
							"Take all the gold!",
							"Take half of the gold.",
							"Take the shining idol in the back",
							"Leave without taking anything, coward...");
	int vaultChoice;
	if (burglar->getVaultKey()) {
		if (searched) {
			std::cout << "You've already searched this room, get out quick bud!\n" << std::endl;
		}
		else {
			std::cout << "You pull out the key you found earlier and stick it in the key hole, as you turn" << std::endl;
			std::cout << "the key you here the pins shift as the door begins to open. We're in buddy!"  << std::endl;

			std::cout << "\nInside you see mounds of gold, and a shining idol in the back corner...\n" << std::endl;

			do {
				vaultOptions.prompt();
				vaultChoice = vaultOptions.getResponse();

				if (vaultChoice == 1){
					std::cout << "You begin cramming all the money into your burlap sack, I don't think it'll" << std::endl;
					std::cout << "all fit buddy.\n" << std::endl;

					searched = true;
					police->chanceIncrease(50);
				}
				else if (vaultChoice == 2) {
					std::cout << "You carefully pick out half of the gold bars.  Making sure only to grab the" << std::endl;
					std::cout << "most shiny ones, weirdo.\n" << std::endl;

					searched = true;
					police->chanceIncrease(25);
				}
				else if (vaultChoice == 3) {
					std::cout << "You approach the shining idol in the back, and in a moment of Indiana Jones-esque" << std::endl;
					std::cout << "fashion, you swap the idol with a gold bar." << std::endl;
					std::cout << "\nSirens begin to wail, looks like you messed up bud.\n" << std::endl;

					searched = true;
					police->chanceIncrease(100);

				}
				else if (vaultChoice == 4) {
					std::cout << "UGH, seriously, we came all this way and you chose nothing? Just get out, NOW\n" << std::endl;
					searched = true;
				}
				else {
					std::cout << "Ugh, I don't know why I chose you for this heist, pick again doofus.\n" << std::endl;
				}
			} while (vaultChoice < 1 || vaultChoice > 4);
		}
	}
}
