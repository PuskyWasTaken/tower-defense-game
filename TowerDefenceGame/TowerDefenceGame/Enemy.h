#pragma once
#include"MovableEntity.h" 

class Enemy : public MovableEntity
{
public:

	Enemy(const sf::Vector2f position, const sf::Vector2f size, const float speed, const sf::Vector2i movementDirection, const uint16_t health);
	Enemy();
	~Enemy();

private:

	uint16_t health;
	bool alive = true;

public:

	uint16_t getHealth() const;
	bool isAlive() const;

	void setHealth(uint16_t health);
	void setAlive(bool alive);

};

