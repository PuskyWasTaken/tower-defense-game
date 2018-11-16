#pragma once
#include "IStateClass.h"
#include <SFML/Graphics.hpp>
#include <thread>

class Game : public IStateClass
{
public:
	Game();
	~Game();

private:
	
	/* TODO: Implement threads */
	//sf::Thread
	//std::thread gameThread;

	/// TO DO: Delete
	sf::RectangleShape aPlaceHolderRect;
	float directionX;
	float directionY;
	const float speed = 1.5f;
	///

	/* Pusky TODO: Add a std::vector of intersections,*/


public: 
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);
	//void readLevel();
};

