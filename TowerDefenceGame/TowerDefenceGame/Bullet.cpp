#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f& position, const sf::RectangleShape& destination, const float speed)
	: MovableEntity(position, sf::Vector2f(10, 10), speed, sf::Vector2i(0, 0)), m_isDestinationAchieved(false)
{
	this->m_destination = destination;
}

Bullet::Bullet()
	: MovableEntity(sf::Vector2f(0, 0), sf::Vector2f(10, 10), 0.f, sf::Vector2i(0, 0)), m_isDestinationAchieved(false)
{}

Bullet::~Bullet()
{}

void Bullet::update()
{
	if (this->m_isDestinationAchieved)
		return;

	if (this->isCollisionWithRect(m_destination))
	{
		this->m_isDestinationAchieved = true;
		return;
	}
	
	updateMovementDirections();
	this->move();

}

void Bullet::setDestination(const sf::RectangleShape& destination)
{
	this->m_destination = destination;
}

bool Bullet::isDestinationAchieved() const
{
	return this->m_isDestinationAchieved;
}

void Bullet::updateMovementDirections()
{
	if (m_destination.getPosition().x + m_destination.getSize().x/2 > this->getCenter().x)
		setMovementX(1.0f);
	else if (m_destination.getPosition().x + m_destination.getSize().x / 2 < this->getCenter().x)
		setMovementX(-1.0f);
	else 
		setMovementX(0.f);

	if (m_destination.getPosition().y + m_destination.getSize().y / 2 > this->getCenter().y)
		setMovementY(1.0f);
	else if (m_destination.getPosition().y + m_destination.getSize().y / 2 > this->getCenter().y)
		setMovementY(-1.0f);
	else
		setMovementY(0.f);
}

