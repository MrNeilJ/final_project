//
// Created by Neil on 6/6/2017.
//

#include "Cops.hpp"
#include <memory>
#include <iostream>

Cops::Cops() {
	triggerChance = 0;
	roundsTilCaught = 10;
	copsCalled = false;
}

void Cops::chanceIncrease(int chance) {
	int randNum = (rand() % 100) + 1;
	triggerChance += chance;

	// Trigger one set of chances
	if (randNum < triggerChance) {
		copsCalled = true;
		std::cout << "You hear sirens wailing in the distance, looks like you've been caught bud..." << std::endl;
		std::cout << "Grab what you can and get out ASAP!" << std::endl;
	}
}

int Cops::getRoundsTilCaught() {
	return roundsTilCaught;
}

void Cops::roundSubtract() {
	roundsTilCaught --;
}

bool Cops::wereCopsCalled() {
	return copsCalled;
}
