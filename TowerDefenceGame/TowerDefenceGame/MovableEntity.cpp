#include "MovableEntity.h"


MovableEntity::MovableEntity( const sf::Vector2f position,
							  const sf::Vector2f size,
							  const float speed,
							  const sf::Vector2i movementDirection )

	: Entity(position, size), speed(speed), movementDirection(movementDirection)
{}

MovableEntity::~MovableEntity()
{}

void MovableEntity::setSpeed(float speed)
{
	this->speed = speed;
}

void MovableEntity::setMovementDirection(const sf::Vector2i& movementDirection)
{
	this->movementDirection = movementDirection;
}

void MovableEntity::setMovementX(const int direction)
{
	setMovementDirection(sf::Vector2i(direction, movementDirection.y));
}

void MovableEntity::setMovementY(const int direction)
{
	setMovementDirection(sf::Vector2i(movementDirection.x, direction));
}

int MovableEntity::getMovementX() const
{
	return this->movementDirection.x;
}

int MovableEntity::getMovementY() const
{
	return this->movementDirection.y;
}

void MovableEntity::move()
{
	setPosition(sf::Vector2f(movementDirection.x * speed + getPosition().x, movementDirection.y  * speed + getPosition().y));
}
