#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

uint16_t Enemy::getHealth() const
{
	return this->health;
}

bool Enemy::getAlive() const
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

sf::Vector2f Enemy::getPosition()
{
	return sf::Vector2f(); /* TODO */
}

void Enemy::setPosition(sf::Vector2f centeredPosition)
{
	/* TODO */
}
