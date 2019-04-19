#pragma once
#include <SFML/Graphics.hpp>
#include "missile.h"
#include "Bomb.h"
using namespace std;
using namespace sf;
class enemy {
private:
	Sprite theEnemy[10]; //array of enemy sprites
	bool alive[10] = { true,true,true,true,true,true,true,true,true,true }; // array of bools t if related enemy is alive
	Texture enemyTexture; //enemy texture

	int getRandID(); //Random number generator
	int kills; //# of kills
	bool fired;
public:
	enemy(); //default constructor
	void draw(RenderWindow& win); //draws the enemies
	bool checkDeath(missile theMissiles); //checks if enemies are shot
	void reset(); //resets all enemies
	void bombFire();//drops bombs
	bomb theBombs; //bomb object
};