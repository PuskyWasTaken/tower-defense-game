#include "Game.h"
#include <time.h>
#include <stdlib.h>


Game::Game()
{
	/// TO DO: Delete
	someEnemy.setColour(sf::Color::Blue);
	someEnemy.setMovementX(-1);
	someEnemy.setSpeed(1.f);
	someEnemy.setCenterPosition(sf::Vector2f(800 - someEnemy.getWidth()/2, 400));

	enemyArray.push_back(someEnemy);

	someIntersection.setColour(sf::Color::Red);
	someIntersection.setSize(sf::Vector2f(60, 60));
	someIntersection.setCenterPosition(sf::Vector2f(400,400));
	someIntersection.setEntrance(static_cast<short>(Intersection::cardinals::East), true);

	intersectionArray.push_back(someIntersection);

	Intersection anotherIntersection(sf::Vector2f(400,200), sf::Vector2f(60,60));
	anotherIntersection.setColour(sf::Color::Cyan);
	anotherIntersection.setEntrance(static_cast<short>(Intersection::cardinals::South), true);
	intersectionArray.push_back(anotherIntersection);


	Intersection yetAnotherInteresection = { sf::Vector2f(200,200), sf::Vector2f(60,60) };
	yetAnotherInteresection.setEntrance(static_cast<short>(Intersection::cardinals::East), true);
	intersectionArray.push_back(yetAnotherInteresection);

	col.setFillColor(sf::Color::Magenta);
	///
}


Game::~Game()
{}

void Game::update(sf::RenderWindow &window)
{
	handleEvent(window);
	updateEnemyMovements();
}

void Game::draw(sf::RenderWindow & window)
{
	/// TO DO: Delete

	/* Basic example showing movement */
	someEnemy.move();

	/* Draw our beautiful enemy */
	window.draw(someEnemy);
	for ( Intersection i : intersectionArray)
		window.draw(i);

	window.draw(col);
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

			/* What side it collided on should be disabled */
			intersectionArray[i].setEntrance(getEntranceSide(enemy), false);

		}
		else if (enemy.isCollision(intersectionArray[i]))
		{
			/* If the enemy is in the center of the intersection */
			sf::RectangleShape collisionArea = enemy.getCollision(intersectionArray[i]);
			if (!(collisionArea.getPosition().x + collisionArea.getSize().x != intersectionArray[i].getCenteredPosition().x
				&& collisionArea.getPosition().y + collisionArea.getSize().y != intersectionArray[i].getCenteredPosition().y))
			{
				srand(time(nullptr));
				short random;
				do
				{
					random = rand() % 4;

				} while (!intersectionArray[i].hasEntrance(random));

				enemy.setMovementDirection(getMovementDirection(random));
				enemy.setIsDuringCollision(false);

				/// TODO : Delete line bellow
				col = collisionArea;
			}
		}
	}
}

short Game::getEntranceSide(const Enemy& enemy)
{
	/* Find out where did the enemy come from */
	if (enemy.getMovementX() > 0)
		return static_cast<short>(Intersection::cardinals::West);
	else if (enemy.getMovementX() > 0)
		return static_cast<short>(Intersection::cardinals::East);
	else if (enemy.getMovementY() < 0)
		return static_cast<short>(Intersection::cardinals::North);
	else if (enemy.getMovementY() > 0)
		return static_cast<short>(Intersection::cardinals::South);

	/* TO DO: Add throw here */
	return 0;
}

sf::Vector2i Game::getMovementDirection(const short entrance) const
{
	if (entrance == 0)
		return sf::Vector2i(-1,0);
	else if (entrance == 1)
		return sf::Vector2i(1,0);
	else if (entrance == 2)
		return sf::Vector2i(0,-1);
	else if (entrance == 3)
		return sf::Vector2i(0,1);

}



