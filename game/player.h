#pragma once
#include <iostream>
#include "missile.h"
#include "ship.h"
#include "bomb.h"
class player
{
private:
	int lives; //#of remaining lives

public:
	player(); //default constructor
	int getLives();
	void resetLives();
	bool checkPlayerDeath(bomb b, ship s);

};
