#include "Tower.h"



Tower::Tower()
{
}


Tower::~Tower()
{
}

sf::RectangleShape Tower::getHitbox()
{
	return this->hitbox;
}

sf::VertexArray Tower::getSprite()
{
	return this->sprite;
}
sf::Vector2f Tower::getPosition()
{
	return (sf::Vector2f(positionX + (1 / 2 * positionX), (positionY + (1 / 2 * positionY))));
}

void Tower::setPosition(sf::Vector2f centeredPosition)
{
	centeredPosition = sf::Vector2f(positionX + (1 / 2 * positionX), (positionY + (1 / 2 * positionY)));
}

float Tower::getDamage()
{
	return this->damage;
}

