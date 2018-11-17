#pragma once
#include "SFML/Graphics.hpp"

/* Created IEntity class for game objects */

class IEntity
{
public:
	virtual ~IEntity() {};

	virtual sf::RectangleShape getHitbox() = 0;
	virtual sf::VertexArray getSprite() = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setPosition(sf::Vector2f centeredPosition) = 0;

};