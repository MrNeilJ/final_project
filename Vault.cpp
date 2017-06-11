//
// Created by Neil on 6/7/2017.
//

#include <iostream>
#include "Vault.hpp"
#include "menuMaker.hpp"

Vault::Vault() {
	searched = false;
	setLock(true);
}

void Vault::roomDescription() {
	if (getFoundKey()) {
		std::cout << "You open the door, and see the large silver shielded door labeled Vault. You" << std::endl;
		std::cout << "pull out the key you found earlier and stick it in the key hole, as you turn" << std::endl;
		std::cout << "the key you here the pins shift as the door begins to open. We're in buddy!"  << std::endl;
	}
	if (!getFoundKey()) {
		std::cout << "You open the door, and see the large silver shielded door, you attempt to push " << std::endl;
		std::cout << "it open, but it won't budge, looks like you'll need to find that key after all." << std::endl;
	}

}

int Vault::examine() {
	menuMaker vaultOptions(	"What would you like to do?",
							"Take all the gold!",
							"Take half of the gold.",
							"Take the shining idol in the back",
							"Leave without taking anything, coward...");
	int vaultChoice;
	if (getFoundKey()) {
		if (searched) {
			std::cout << "You've already searched this room, get out quick bud!" << std::endl;
			return 0;
		}
		std::cout << "Inside you see mounds of gold, and a shining idol in the back corner..." << std::endl;

		do {
			vaultOptions.prompt();
			vaultChoice = vaultOptions.getResponse();

			if (vaultChoice == 1){
				std::cout << "You begin cramming all the money into your burlap sack, I don't think it'll" << std::endl;
				std::cout << "all fit buddy." << std::endl;

				searched = true;
			}
			else if (vaultChoice == 2) {
				std::cout << "You carefully pick out half of the gold bars.  Making sure only to grab the" << std::endl;
				std::cout << "most shiny ones, weirdo." << std::endl;

				searched = true;
			}
			else if (vaultChoice == 3) {
				std::cout << "You approach the shining idol in the back, and in a moment of Indiana Jones-esque" << std::endl;
				std::cout << "fashion, you swap the idol with a gold bar." << std::endl;
				std::cout << "\nSirens begin to wail, looks like you messed up bud." << std::endl;

				searched = true;
			}
			else if (vaultChoice == 4) {
				std::cout << "UGH, seriously, we came all this way and you chose nothing? Just get out, NOW" << std::endl;

				searched = true;
			}
			else {
				std::cout << "Ugh, I don't know why I chose you for this heist, pick again doofus." << std::endl;
			}
		} while (vaultChoice < 1 || vaultChoice > 4);


	}
}
