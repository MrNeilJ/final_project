//
// Created by Neil on 6/11/2017.
//

#ifndef FINAL_PROJECT_STARTROOM_HPP
#define FINAL_PROJECT_STARTROOM_HPP


#include "Robber.hpp"
#include "Cops.hpp"
#include "Room.hpp"

class StartRoom : public Room{
private:

public:
	virtual int moveMenu();
	void roomDescription();
	void examine(Robber* burglar, Cops* police);

};


#endif //FINAL_PROJECT_STARTROOM_HPP
