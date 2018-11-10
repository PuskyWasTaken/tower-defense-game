#include "Application.h"

Application::Application(const std::string& name, const int32_t x, const int32_t y)
	: window(sf::VideoMode(x, y), name)
{
	/* Run at 60fps - Actually it runs at the refresh rate of the monitor */
	//window.setVerticalSyncEnabled(true);
}

Application::~Application()
{
	/* TO DO: If needed */
}

void Application::operator()()
{
	/* Notify that we are indeed running the game now */
	isRunning = true;

	/* Run the game loop */
	gameLoop();

}

void Application::gameLoop()
{
	/// TO DO: Delete
	
	/* Create a square of size 40,40 */
	sf::RectangleShape rect(sf::Vector2f(40.0f, 40.0f));

	/* Set the color to green */
	rect.setFillColor(sf::Color(100, 250, 50));

	/* Center it to the screen */
	rect.setPosition(sf::Vector2f(getSize().x / 2 - rect.getSize().x / 2, getSize().y / 2 - rect.getSize().y / 2));
	float direction = 1.0f;
	float speed = 1.5f;

	///	
	
	/* Used for restricting the Update Loop to a fixed frame rate */
	sf::Clock updateClock;
	updateClock.restart();

	/* Update */
	while ( isRunning && window.isOpen() )
	{
		/* Handling of events should be done as fast as the graphics card allows */
		handleEvent();
		
		/* Elapsed time between frames */
		sf::Time elapsedTime = updateClock.getElapsedTime();
		
		/* Fixed Update */
		if (elapsedTime > this->frameTime)
		{
			/* Reset our timer */
			updateClock.restart();

			/* Clear previous frame */
			window.clear();
				
			/// TO DO: Delete
			
			/* Basic example showing movement */
			if (rect.getPosition().x + rect.getSize().x == getSize().x)
				direction = -1.0f;
			else if (rect.getPosition().x == 0)
				direction = 1.0f;

			rect.move(sf::Vector2f(speed * direction, 0.0f));

			/* Draw our beautiful rectangle */
			window.draw(rect);

			///
			
			/* Display the new frame */
			window.display();
		}
	}
}

void Application::handleEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Left)
			{ /* TODO: Further thinking about the event handling */ }
	}
}
