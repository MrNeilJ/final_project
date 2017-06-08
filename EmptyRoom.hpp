//
// Created by Neil on 6/7/2017.
//

#ifndef FINAL_PROJECT_EMPTYROOM_HPP
#define FINAL_PROJECT_EMPTYROOM_HPP


#include "Room.hpp"
#include "Cops.hpp"

class EmptyRoom : public Room {
private:
	bool searched;

public:
	EmptyRoom();
	void roomDescription();
	int examine(Cops*);

};


#endif //FINAL_PROJECT_EMPTYROOM_HPP
