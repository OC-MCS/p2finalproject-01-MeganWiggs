#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "missile.h"
#include <list>
using namespace std;
using namespace sf;
class ship {
private:
	Sprite theShip; //ship sprite
	Texture shipTexture; //ship texture
public:
	missile missiles; //missiles object
	ship(); //Sets ship defaults
	void move(); //moves and fires missiles
	void draw(RenderWindow& win); //renders the ship
	missile getMissile(); //returns Missile
	void fire(); //Fires missile
	Sprite getShip() { //Returns theShip
		return theShip;
	}

};