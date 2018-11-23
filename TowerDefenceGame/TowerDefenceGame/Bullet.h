#pragma once
#include "MovableEntity.h"

class Bullet :
	public MovableEntity
{
public:
	Bullet(const sf::Vector2f& position, const sf::RectangleShape& destination, const float speed);
	Bullet();
	~Bullet();

private:
	sf::RectangleShape destination;
	bool isDestinationAchieved;

private:
	void updateMovementDirections();

public:

	void update();
	void setDestination(const sf::RectangleShape& destination);

};
