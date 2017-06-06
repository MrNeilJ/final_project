//
// Created by Neil on 6/6/2017.
//

#include "Room.hpp"

int Room::examine() {
	return 0;
}

bool Room::getRoom(int direction) {
	return false;
}

Room* Room::moveRoom(int direction) {
	if (direction == 1) {
		return North;
	}
	else if (direction == 2) {
		return South;
	}
	else if (direction == 3) {
		return East;
	}
	else {
		return West;
	}
}

void Room::enterRoom() {

}

void Room::roomDescription() {

}
