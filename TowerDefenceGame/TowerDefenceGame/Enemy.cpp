#include "Enemy.h"


Enemy::Enemy( const sf::Vector2f& position,
			  const sf::Vector2f& size,
			  const float speed,
			  const sf::Vector2i& movementDirection,
			  const uint16_t health )

	: MovableEntity(position, size, speed, movementDirection), health(health)
{
}

Enemy::Enemy()
	: MovableEntity(sf::Vector2f(0, 0), sf::Vector2f(Globals::enemySize, Globals::enemySize), Globals::defaultEnemyMoveSpeed, sf::Vector2i(0, 0) ), health(Globals::defaultEnemyHealth)
{
}

Enemy::~Enemy()
{
}

int16_t Enemy::getHealth() const
{
	return this->health;
}

bool Enemy::isAlive() const
{
	return this->alive;
}

bool Enemy::isInCollision() const
{
	return this->isDuringCollision;
}

void Enemy::setHealth(const int16_t health)
{
	this->health = health;
}

void Enemy::setAlive(const bool alive)
{
	this->alive = alive;
}

void Enemy::setIsDuringCollision(const bool isDuringCollision)
{
	this->isDuringCollision = isDuringCollision;
}

