#include "ship.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

ship::ship() {
	theShip.setPosition(400, 500);
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	theShip.setTexture(shipTexture);


}
void ship::draw(RenderWindow& win) {
	win.draw(theShip);
	missiles.draw(win);

}

void ship::move() {

	const float DISTANCE = 5.0f;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		if (theShip.getPosition().x > 0) {
			theShip.move(-DISTANCE, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		if (theShip.getPosition().x < 780) {
			theShip.move(DISTANCE, 0);
		}
	}




}


missile ship::getMissile() {
	return missiles;
}

void ship::fire() {
	missiles.fire(theShip.getPosition().x, theShip.getPosition().y);
}

