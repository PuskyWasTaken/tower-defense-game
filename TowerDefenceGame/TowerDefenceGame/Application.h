#pragma once
#include <SFML\Graphics.hpp>



class Application
{
public:
	Application(const std::string& title, const int32_t x, const int32_t y);
	~Application();

	/* The operator starts the game loop basically */
	void operator () ();

private:
	sf::RenderWindow window;
	sf::Event event;

	bool isRunning;

	/* Time to render a frame - Unties the game from the graphics card */
	const sf::Time frameTime = sf::seconds(1.0f / 120.f);


public:
	/* Event handling */
	void handleEvent();
	void gameLoop();

public:

	/* Getters */
	sf::Vector2u getSize()
	{
		return window.getSize();
	}

	/* Setters */
	void setTitle(const std::string& newTitle)
	{
		window.setTitle(newTitle);
	}
	void setSize(const int32_t x, const int32_t y)
	{
		window.setSize(sf::Vector2u(x, y));
	}

};


