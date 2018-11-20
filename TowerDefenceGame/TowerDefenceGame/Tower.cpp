#include "Tower.h"


Tower::Tower()
	: UnmovableEntity(sf::Vector2f(0,0), sf::Vector2f(40,40)), damage(10)
{
}

Tower::Tower(const sf::Vector2f& position, const sf::Vector2f& size, const float damage)
	: UnmovableEntity(position, size), damage(damage)
{
}


Tower::~Tower()
{
}

float Tower::getDamage() const
{
	return this->damage;
}

