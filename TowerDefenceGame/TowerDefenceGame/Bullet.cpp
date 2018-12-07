#include "Bullet.h"


Bullet::Bullet(const sf::Vector2f& position, const Enemy& destination, const float speed)
	: MovableEntity(position, Globals::defaultBulletSize, speed, sf::Vector2i(0, 0)), m_isDestinationAchieved(false)
{
	this->m_destination = destination;
}

Bullet::Bullet()
	: MovableEntity(sf::Vector2f(0, 0), Globals::defaultBulletSize, Globals::defaultBulletSpeed, sf::Vector2i(0, 0)), m_isDestinationAchieved(false)
{}

Bullet::~Bullet()
{}

void Bullet::update()
{
	if (this->m_isDestinationAchieved)
		return;

	if (this->isCollision(m_destination))//this->isCollisionWithRect(m_destination.getHitbox()))
	{
		this->m_isDestinationAchieved = true;
		return;
	}

	/* Do the movement */
	updateMovementDirections();
	this->moveTo(sf::Vector2f(this->m_speed * cosf(m_degree), this->m_speed * sinf(m_degree)));

}

void Bullet::setDestination(const Enemy& destination)
{
	this->m_destination = destination;
}

bool Bullet::isDestinationAchieved() const
{
	return this->m_isDestinationAchieved;
}

void Bullet::updateMovementDirections()
{
	sf::Vector2f distance;

	/* Calculate the distance between our bullet and the center of our destination */
	distance.x = fabs(this->getPosition().x - m_destination.getCenter().x);
	distance.y = fabs(this->getPosition().y - m_destination.getCenter().y);

	/* Calculate the degree we have to move at */
	float degree = atan2f(distance.y, distance.x);

	this->m_degree = degree;
	
}


