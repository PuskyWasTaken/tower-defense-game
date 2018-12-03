#include "Game.h"

Game::Game()
{
	/// TO DO: Delete
	someEnemy.setColour(sf::Color::Blue);
	someEnemy.setMovementX(-1);
	someEnemy.setSpeed(2.f);
	someEnemy.setCenterPosition(sf::Vector2f(700 - someEnemy.getWidth() / 2, 400));

	enemyArray.push_back(someEnemy);

	someIntersection.setColour(sf::Color::Red);
	someIntersection.setSize(sf::Vector2f(60, 60));
	someIntersection.setCenterPosition(sf::Vector2f(400, 400));
	someIntersection.setExit(0);

	intersectionArray.push_back(someIntersection);

	Intersection anotherIntersection(sf::Vector2f(400, 200), sf::Vector2f(60, 60), 2);
	anotherIntersection.setColour(sf::Color::Cyan);
	intersectionArray.push_back(anotherIntersection);


	Intersection yetAnotherInteresection = { sf::Vector2f(200,200), sf::Vector2f(60,60), 2 };
	intersectionArray.push_back(yetAnotherInteresection);

	col.setFillColor(sf::Color::Magenta);

	//Enemy someOtherEnemy;
	someOtherEnemy.setColour(sf::Color::Yellow);
	someOtherEnemy.setMovementX(0);
	someOtherEnemy.setSpeed(0.f);
	someOtherEnemy.setCenterPosition(sf::Vector2f(300, 100));
	enemyArray.push_back(someOtherEnemy);

	//bullet.setDestination(someOtherEnemy.getHitbox());
	//bullet.setSpeed(0.5f);
	//bullet.setColour(sf::Color::Blue);

	/* Create some random tower */
	someTower.setSize(sf::Vector2f(100, 100));
	someTower.setCenterPosition(sf::Vector2f(50, 50));
	someTower.setColour(sf::Color::Magenta);
	someTower.setIntruder(enemyArray[0]);

	///
}


Game::~Game()
{}

void Game::update(sf::RenderWindow &window)
{
	handleEvent(window);
	updateEnemyMovements();
	someTower.update();
}

void Game::draw(sf::RenderWindow & window)
{

	for (int i = 0; i < enemyArray.size(); ++i)
		enemyArray[i].move();
	
	/* Basic example showing movement */

	/* Draw our beautiful enemies */
	for (Enemy i : enemyArray)
		window.draw(i);

	/* Draw the intersections */
	for (Intersection i : intersectionArray)
		window.draw(i);

	window.draw(col);
	window.draw(someTower);
}

void Game::handleEvent(sf::RenderWindow &window)
{
	/// TO DO: Delete

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
	}

	///

}

void Game::updateEnemyMovements()
{
	/* Go through the enemyArray and update the movement of each of them according with what intersections they collide with */
	for (int i = 0; i < enemyArray.size(); ++i)
		updateEnemyCollision(enemyArray[i]);
}

void Game::updateEnemyCollision(Enemy& enemy)
{
	/* Check for a collision */
	for (int i = 0; i < intersectionArray.size(); ++i)
	{
		/* Check if it's already collided or not */
		if (enemy.isCollision(intersectionArray[i]) && !enemy.isInCollision())
		{
			enemy.setIsDuringCollision(true);

		}
		else if (enemy.isCollision(intersectionArray[i]))
		{
			/* If the enemy is in the center of the intersection */
			if ( intersectionArray[i].getICenter().x == enemy.getICenter().x
				&&  intersectionArray[i].getICenter().y == enemy.getICenter().y ) 
			{
				enemy.setMovementDirection(getMovementDirection(intersectionArray[i].getExit()));
				enemy.setIsDuringCollision(false);

				/// TODO : Delete line bellow
				col = enemy.getCollision(intersectionArray[i]);
			}
		}
	}
}

sf::Vector2i Game::getMovementDirection(const short entrance) const
{
	/* North */
	if (entrance == 0)
		return sf::Vector2i(0,-1);
	/* South */
	else if (entrance == 1)
		return sf::Vector2i(0,1);
	/* East */
	else if (entrance == 2)
		return sf::Vector2i(1,0);
	/* West */
	else if (entrance == 3)
		return sf::Vector2i(-1,0);
}



