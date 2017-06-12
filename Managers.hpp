//
// Created by Neil on 6/7/2017.
//

#ifndef FINAL_PROJECT_MANAGERS_HPP
#define FINAL_PROJECT_MANAGERS_HPP


#include "Room.hpp"

class Managers : public Room {
private:
	bool searched;

public:
	Managers();
	void roomDescription();
	void examine(Robber*, Cops*);
};



#endif //FINAL_PROJECT_MANAGERS_HPP
