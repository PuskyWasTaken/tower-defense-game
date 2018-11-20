#include "Bullet.h"


Bullet::Bullet(const sf::Vector2f & position, const sf::Vector2f & size, const float speed, const sf::Vector2i & movementDirection)
	: MovableEntity(position, size, speed, movementDirection)
{}

Bullet::Bullet()
	: MovableEntity(sf::Vector2f(0, 0), sf::Vector2f(40, 40), 0.f, sf::Vector2i(0, 0))
{}

Bullet::~Bullet()
{}
