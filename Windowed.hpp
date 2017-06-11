//
// Created by Neil on 6/7/2017.
//

#ifndef FINAL_PROJECT_WINDOWED_HPP
#define FINAL_PROJECT_WINDOWED_HPP


#include "Room.hpp"

class Windowed : public Room {
private:
	bool searched;

public:
	Windowed();
	void roomDescription();
	int examine();
};


#endif //FINAL_PROJECT_WINDOWED_HPP
