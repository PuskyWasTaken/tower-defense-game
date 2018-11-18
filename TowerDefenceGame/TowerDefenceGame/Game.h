#pragma once
#include "IStateClass.h"
#include <SFML/Graphics.hpp>
#include <thread>

#include "Enemy.h"
#include "Intersection.h"

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
	Enemy someEnemy;
	Intersection someIntersection;


	/* Pusky TODO: Add a std::vector of intersections,*/


public: 
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);

	//void readLevel();
};

