#pragma once
#include "SFML/Graphics.hpp"

class IStateClass
{
public:
	virtual ~IStateClass() {};

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void handleEvent() = 0;

};
