#include "Unmovable.h"



Unmovable::Unmovable()
{
}


Unmovable::~Unmovable()
{
}

sf::RectangleShape Unmovable::getHitbox()
{
	return this->hitbox;
}

sf::VertexArray Unmovable::getSprite()
{
	return this->sprite;
}

sf::Vector2f Unmovable::getPosition()
{
	return (sf::Vector2f(positionX + (1 / 2 * positionX), (positionY + (1 / 2 * positionY))));
}

void Unmovable::setPosition(sf::Vector2f centeredPosition)
{
	centeredPosition = (sf::Vector2f(positionX + (1 / 2 * positionX), (positionY + (1 / 2 * positionY))));
}
