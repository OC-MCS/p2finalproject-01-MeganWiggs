#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Bomb.h"
#include <time.h>
using namespace std;
using namespace sf;

void bomb::fire(int x, int y) {
	bombs.push_front(new Sprite);
	if (!bombTexture.loadFromFile("bomb.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	bombs.front()->setTexture(bombTexture);
	bombs.front()->setPosition(x, y);
}

void bomb::draw(RenderWindow& win) {
	for (list<Sprite*>::iterator it = bombs.begin(); it != bombs.end(); ++it) {
		Sprite* temp = *it;
		Sprite tempsprite = *temp;
		(*it)->move(0, 0.6);
		win.draw(tempsprite);

	}
}

list <Sprite*> bomb::getList() {
	return bombs;
}