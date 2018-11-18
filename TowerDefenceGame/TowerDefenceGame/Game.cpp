#include "Game.h"



Game::Game()
{
	/// TO DO: Delete
	someEnemy.setColour(sf::Color::Blue);
	someEnemy.setMovementX(-1);
	someEnemy.setSpeed(1.f);
	someEnemy.setCenterPosition(sf::Vector2f(100, 100));

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
