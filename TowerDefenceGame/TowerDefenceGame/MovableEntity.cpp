#include "MovableEntity.h"



MovableEntity::MovableEntity()
{
}


MovableEntity::~MovableEntity()
{
}

sf::RectangleShape MovableEntity::getHitbox()
{
	return this->hitbox;
}

sf::VertexArray MovableEntity::getSprite()
{
	return this->sprite;
}

sf::Vector2f MovableEntity::getPosition()
{
	return (sf::Vector2f(positionX + (1 / 2 * positionX), (positionY + (1 / 2 * positionY))));
}

void MovableEntity::setPosition(sf::Vector2f centeredPosition)
{
	centeredPosition = (sf::Vector2f(positionX + (1 / 2 * positionX), (positionY + (1 / 2 * positionY))));
}

void MovableEntity::setSpeed(float speed)
{
	this->speed = speed;
}

void MovableEntity::Move()
{
	/* TODO: implement */
}
