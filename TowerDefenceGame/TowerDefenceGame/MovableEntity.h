#pragma once
#include "Entity.h"

class MovableEntity : public Entity
{
public:
	MovableEntity(const sf::Vector2f& position, const sf::Vector2f& size, const float speed, const sf::Vector2i& movementDirection );
	~MovableEntity();
	

protected:

	float speed;

private:

	sf::Vector2i movementDirection;

public:

	void setSpeed(const float speed);
	void setMovementDirection(const sf::Vector2i& movementDirection);
	void setMovementX(const int direction);
	void setMovementY(const int direction);

	int getMovementX() const;
	int getMovementY() const;

	void move();

};

