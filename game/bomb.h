#pragma once
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;



class bomb {
private:
	list< Sprite*> bombs;//list of bombs dropped
	Texture bombTexture; //bomb texture

public:
	void fire(int x, int y); //fires a bomb
	void draw(RenderWindow& win); //draws all the bombs
	list <Sprite*> getList(); //returns list of bombs
};

