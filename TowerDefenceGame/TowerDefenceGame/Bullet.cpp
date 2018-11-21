#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f& position, const sf::RectangleShape& destination, const float speed)
	: MovableEntity(position, sf::Vector2f(10, 10), speed, sf::Vector2i(0, 0)), isDestinationAchieved(false)
{
	this->destination = destination;
}

Bullet::Bullet()
	: MovableEntity(sf::Vector2f(0, 0), sf::Vector2f(10, 10), 0.f, sf::Vector2i(0, 0)), isDestinationAchieved(false)
{}

Bullet::~Bullet()
{}

void Bullet::update()
{
	if (this->isDestinationAchieved)
		return;

	if (this->isCollisionWithRect(destination))
	{
		this->isDestinationAchieved = true;
		return;
	}
	
	updateMovementDirections();
	this->move();

}

void Bullet::setDestination(const sf::RectangleShape& destination)
{
	this->destination = destination;
}

void Bullet::updateMovementDirections()
{
	if (destination.getPosition().x + destination.getSize().x/2 > this->getCenter().x)
		setMovementX(1.0f);
	else if (destination.getPosition().x + destination.getSize().x / 2 < this->getCenter().x)
		setMovementX(-1.0f);
	else 
		setMovementX(0.f);

	if (destination.getPosition().y + destination.getSize().y / 2 > this->getCenter().y)
		setMovementY(1.0f);
	else if (destination.getPosition().y + destination.getSize().y / 2 > this->getCenter().y)
		setMovementY(-1.0f);
	else
		setMovementY(0.f);
}

