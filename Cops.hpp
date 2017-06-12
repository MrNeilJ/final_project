//
// Created by Neil on 6/6/2017.
//

#ifndef FINAL_PROJECT_COPS_HPP
#define FINAL_PROJECT_COPS_HPP


class Cops {
private:
	int triggerChance;
	int roundsTilCaught;
	bool copsCalled;
public:
	Cops();
	void chanceIncrease(int chance);

	int getRoundsTilCaught();
	void roundSubtract();
	bool wereCopsCalled();
};


#endif //FINAL_PROJECT_COPS_HPP
