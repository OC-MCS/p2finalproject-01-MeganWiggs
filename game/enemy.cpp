#include "enemy.h"
#include "missile.h"
#include <iostream>
#include <string>
#include "Bomb.h"
using namespace std;

enemy::enemy() {
	kills = 0;
	fired = false;
	if (!enemyTexture.loadFromFile("enemy.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 10; i++) {
		theEnemy[i].setTexture(enemyTexture);
		theEnemy[i].setPosition((70 * i + 50), 100);

	}
}

void enemy::draw(RenderWindow & win) {
	for (int i = 0; i < 10; i++) {
		theEnemy[i].move(0, 0.2);
		if (alive[i]) {
			win.draw(theEnemy[i]);
			theBombs.draw(win);
		}
	}
	if (theEnemy[1].getPosition().y >= 500) {
		reset();
	}
}

bool enemy::checkDeath(missile theMissiles) {
	list <Sprite*> missileList = theMissiles.getList();

	for (int i = 0; i < 10; i++) {
		for (list<Sprite*>::iterator it = missileList.begin(); it != missileList.end(); ++it) {
			if (theEnemy[i].getGlobalBounds().intersects((*it)->getGlobalBounds())) {
				(*it)->setPosition(-100, -100);
				alive[i] = false;
				return true;
			}
		}
	}
	kills = 0;
	for (int i = 0; i < 10; i++) {
		if (!alive[i]) {
			kills++;
		}
		if (kills == 10) {
			cout << "level won" << endl;
			reset();
			for (int i = 0; i < 10; i++) {
				theEnemy[i].scale(0.7, 0.7);
			}
		}
	}

	return false;
}

void enemy::reset() {
	for (int i = 0; i < 10; i++) {
		theEnemy[i].setPosition((70 * i + 50), 100);
		alive[i] = true;
	}
}

void enemy::bombFire() {
	int ID = getRandID();
	if (alive[ID]) {
		theBombs.fire(theEnemy[ID].getPosition().x, theEnemy[ID].getPosition().y);
	}
	else {
		for (ID = 0; ID < 10 && !fired; ID++) {
			if (alive[ID]) {
				theBombs.fire(theEnemy[ID].getPosition().x, theEnemy[ID].getPosition().y);
				fired = true;
			}
			if (ID == 9 && !alive[ID]) {
				fired = true;
			}
		}
	}
}


int enemy::getRandID() {
	srand(time(NULL));
	return (rand() % 10);
}