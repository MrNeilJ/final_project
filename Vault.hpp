//
// Created by Neil on 6/7/2017.
//

#ifndef FINAL_PROJECT_VAULT_HPP
#define FINAL_PROJECT_VAULT_HPP


#include "Room.hpp"

class Vault : public Room {
private:
	bool searched;

public:
	Vault();
	void roomDescription();
	void examine(Robber*, Cops*);
};


#endif //FINAL_PROJECT_VAULT_HPP
