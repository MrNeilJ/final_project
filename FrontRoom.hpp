//
// Created by Neil on 6/11/2017.
//

#ifndef FINAL_PROJECT_FRONTROOM_HPP
#define FINAL_PROJECT_FRONTROOM_HPP


#include "Robber.hpp"
#include "Cops.hpp"
#include "Room.hpp"

class FrontRoom : public Room {
private:
	bool searched;

public:
	FrontRoom();
	void roomDescription();
	void examine(Robber*, Cops*);


};


#endif //FINAL_PROJECT_FRONTROOM_HPP
