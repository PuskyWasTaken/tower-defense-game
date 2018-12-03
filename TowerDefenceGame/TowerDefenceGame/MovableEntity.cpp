#include "MovableEntity.h"


MovableEntity::MovableEntity( const sf::Vector2f& position,
							  const sf::Vector2f& size,
							  const float speed,
							  const sf::Vector2i& movementDirection )

	: Entity(position, size), m_speed(speed), m_movementDirection(movementDirection)
{}

MovableEntity::~MovableEntity()
{}

void MovableEntity::setSpeed(float speed)
{
	this->m_speed = speed;
}

float MovableEntity::getSpeed() const
{
	return m_speed;
}

void MovableEntity::setMovementDirection(const sf::Vector2i& movementDirection)
{
	this->m_movementDirection = movementDirection;
}

void MovableEntity::setMovementX(const int direction)
{
	setMovementDirection(sf::Vector2i(direction, m_movementDirection.y));
}

void MovableEntity::setMovementY(const int direction)
{
	setMovementDirection(sf::Vector2i(m_movementDirection.x, direction));
}

int MovableEntity::getMovementX() const
{
	return this->m_movementDirection.x;
}

int MovableEntity::getMovementY() const
{
	return this->m_movementDirection.y;
}

void MovableEntity::move()
{
	setPosition(sf::Vector2f(m_movementDirection.x * m_speed + getPosition().x, m_movementDirection.y  * m_speed + getPosition().y));
}

void MovableEntity::moveTo(const sf::Vector2f & offset)
{
	this->hitbox.move(offset);
}
