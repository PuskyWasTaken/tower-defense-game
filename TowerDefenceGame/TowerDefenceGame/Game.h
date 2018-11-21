#pragma once
#include "IStateClass.h"
#include <SFML/Graphics.hpp>
#include <thread>

#include "Enemy.h"
#include "Intersection.h"

///
#include "Bullet.h"
///

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
	Intersection someIntersection;
	Enemy someEnemy;
	sf::RectangleShape col;
	Bullet bullet;
	///

	std::vector<Enemy> enemyArray;
	std::vector<Intersection> intersectionArray;

public: 
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);

private:

	void updateEnemyMovements();
	void updateEnemyCollision(Enemy& enemy);
	short getEntranceSide(const Enemy& enemy);
	sf::Vector2i getMovementDirection(const short entrance) const;

	//void readLevel();
};

