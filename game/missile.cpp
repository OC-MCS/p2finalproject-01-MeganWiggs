
#include <iostream>
#include "missile.h"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

missile::missile() {

}

void missile::fire(int x, int y) {
	missiles.push_front(new Sprite);
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	missiles.front()->setTexture(missileTexture);
	missiles.front()->setPosition(x, y);

}

void missile::draw(RenderWindow& win) {
	for (list<Sprite*>::iterator it = missiles.begin(); it != missiles.end(); ++it) {
		Sprite* temp = *it;
		Sprite tempsprite = *temp;
		(*it)->move(0, -5);
		win.draw(tempsprite);
	}

}

list< Sprite*> missile::getList() {
	return missiles;
}