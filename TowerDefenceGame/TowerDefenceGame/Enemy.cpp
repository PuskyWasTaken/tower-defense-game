#include "Enemy.h"


Enemy::Enemy( const sf::Vector2f position,
			  const sf::Vector2f size,
			  const float speed,
			  const sf::Vector2i movementDirection,
			  const uint16_t health )

	: MovableEntity(position, size, speed, movementDirection), health(health)
{
}

Enemy::Enemy()
	: MovableEntity(sf::Vector2f(0, 0), sf::Vector2f(40, 40), 0.f, sf::Vector2i(0, 0) ), health(100)
{
}

Enemy::~Enemy()
{
}

uint16_t Enemy::getHealth() const
{
	return this->health;
}

bool Enemy::isAlive() const
{
	return this->alive;
}

void Enemy::setHealth(uint16_t health)
{
	this->health = health;
}

void Enemy::setAlive(bool alive)
{
	this->alive = alive;
}

