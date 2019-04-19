#include <iostream>
#include "player.h"
#include "ship.h"
#include "bomb.h"
using namespace std;

player::player() {
	lives = 3;
}

int player::getLives() {
	return lives;
}

void player::resetLives() {
	lives = 3;
}

bool player::checkPlayerDeath(bomb b, ship s) {
	list <Sprite*> tempList = b.getList();
	Sprite tempShip = s.getShip();
	for (list<Sprite*>::iterator it = tempList.begin(); it != tempList.end(); ++it) {
		if (tempShip.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
			cout << "hit" << endl;
			(*it)->setPosition(-100, -100);
			lives--;
			return true;
		}

	}
	return false;
}
