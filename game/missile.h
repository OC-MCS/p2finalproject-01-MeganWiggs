#pragma once
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;

class missile {
private:
	list< Sprite*> missiles; //list of missiles
	Texture missileTexture; //missile texture
public:
	missile(); //default constructor
	void fire(int x, int y); //fires a missile
	void draw(RenderWindow& win); //draw all missiles
	list< Sprite*> getList(); //returns list of missile

};