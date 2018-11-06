#pragma once
#include <SFML\Graphics.hpp>

class ManagedWindow
{
public:
	ManagedWindow(const std::string& title, const int32_t x, const int32_t y);
	~ManagedWindow();

	/* The operator starts the game loop basically */
	void operator () ();

private:
	sf::RenderWindow window;

public:
	/* Event handling */
	void handleEvent();

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


