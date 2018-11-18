#include "Game.h"



Game::Game()
{
	/// TO DO: Delete
	someEnemy.setColour(sf::Color::Blue);
	someEnemy.setMovementX(-1);
	someEnemy.setMovementY(1);
	someEnemy.setSpeed(0.5f);
	someEnemy.setCenterPosition(sf::Vector2f(200, 100));

	someIntersection.setColour(sf::Color::Red);
	someIntersection.setPosition(sf::Vector2f(5,200));
	someIntersection.setSize(sf::Vector2f(300, 100));

}


Game::~Game()
{}

void Game::update(sf::RenderWindow &window)
{
	handleEvent(window);
}

void Game::draw(sf::RenderWindow & window)
{
	/// TO DO: Delete

	/* Basic example showing movement */
	someEnemy.move();

	/* Draw our beautiful enemy */
	window.draw(someEnemy);
	window.draw(someIntersection);

	if (someEnemy.isCollision(someIntersection))
	{
		sf::RectangleShape col = someEnemy.getCollision(someIntersection);
		col.setFillColor(sf::Color::Magenta);
		window.draw(col);
	}
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


