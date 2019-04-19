//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
#include "missile.h"
#include "enemy.h"
#include "bomb.h"
#include "ship.h"
#include "player.h"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 

//============================================================
//Megan Wiggs
// Final Program
// thanks for good classes!!
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen

void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
}



int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.

	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		//exit(EXIT_FAILURE);
	}
	
	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// make instances of the ship, missiles, aliens, UI and font
	ship theShip;
	missile missiles;
	enemy enemies;
	player p;
	Font font;
	Text hitCount, lifeCount, startGame;
	int i = 0;
	int hits = 0;
	
	// code for the labels
	font.loadFromFile("C:\\Windows\\Fonts\\Comicbd.ttf");
	
	hitCount.setFont(font);
	hitCount.setString("Hits: ");
	hitCount.setPosition(Vector2f(100, 400));

	lifeCount.setFont(font);
	lifeCount.setString("Lives: ");
	lifeCount.setPosition(Vector2f(100, 450));

	startGame.setFont(font);
	startGame.setString("Press x to start");
	startGame.setPosition(Vector2f(200, 200));
	bool start = false;
	


	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					Sprite ship = theShip.getShip();
					missiles.fire(ship.getPosition().x, ship.getPosition().y);
					// handle space bar
				}
				if (event.key.code == Keyboard::X)
				{
					start = true;
					// handle x
				}

			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background

	
		
		window.draw(background);

		if (!start) {
			window.draw(startGame);
		}

	

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)

	
		else {
			window.draw(hitCount);
			window.draw(lifeCount);
			missiles.draw(window);
			enemies.draw(window);
			theShip.draw(window);
			theShip.move();
			if (enemies.checkDeath(missiles)) {
				hits++;
				hitCount.setString("Hits: " + to_string(hits));
			}
			if (p.checkPlayerDeath(enemies.theBombs, theShip) && p.getLives() == 0) {
				enemies.reset();
				p.resetLives();
			}
			lifeCount.setString("Lives: " + to_string(p.getLives()));

			i++;

			if (i == 60) {
				enemies.bombFire();
				i = 0;
			}

		}
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

