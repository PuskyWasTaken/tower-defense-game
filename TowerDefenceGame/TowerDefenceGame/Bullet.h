#pragma once
#include "MovableEntity.h"
class Bullet :
	public MovableEntity
{
public:
	Bullet(const sf::Vector2f& position, const sf::Vector2f& size, const float speed, const sf::Vector2i& movementDirection);
	Bullet();
	~Bullet();
};

