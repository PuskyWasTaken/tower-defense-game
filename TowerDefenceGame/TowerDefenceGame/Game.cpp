#include "Game.h"



Game::Game()
{
	/// TO DO: Delete

	/* Create a square of size 40,40 */
	aPlaceHolderRect = sf::RectangleShape(sf::Vector2f(40.0f, 40.0f));

	/* Set the color to green */
	aPlaceHolderRect.setFillColor(sf::Color(100, 250, 50));
	
	/* Set it's position to 0,0 */
	aPlaceHolderRect.setPosition(sf::Vector2f(0, 0));

	///	

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
		if (aPlaceHolderRect.getPosition().x + aPlaceHolderRect.getSize().x == window.getSize().x)
			directionX = -1.0f;
		else if (aPlaceHolderRect.getPosition().x == 0)
			directionX = 1.0f;
		
		if(aPlaceHolderRect.getPosition().y + aPlaceHolderRect.getSize().y == window.getSize().y)
			directionY = -1.0f;
		else if (aPlaceHolderRect.getPosition().y == 0)
			directionY = 1.0f;

		aPlaceHolderRect.move(sf::Vector2f(speed * directionX, speed * directionY));

		/* Draw our beautiful rectangle */
		window.draw(aPlaceHolderRect);

		///
}

void Game::handleEvent(sf::RenderWindow &window)
{	
	/// TO DO: Delete

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		directionX = 0.0f;
		directionY = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		directionX = -1.0f;
		directionY = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		directionX = 1.0f;
		directionY = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		directionX = 0.0f;
		directionY = -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		directionX = 0.0f;
		directionY = 1.0f;
	}

	///

}
