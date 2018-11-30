#pragma once
#include"MovableEntity.h" 

class Enemy : public MovableEntity
{
public:

	Enemy(const sf::Vector2f& position, const sf::Vector2f& size, const float speed, const sf::Vector2i& movementDirection, const uint16_t health);
	Enemy();
	~Enemy();

private:

	int16_t health;
	bool alive = true;
	bool isDuringCollision = false;

public:

	int16_t getHealth() const;
	bool isAlive() const;
	bool isInCollision() const;

	void setHealth(const int16_t health);
	void setAlive(const bool alive);
	void setIsDuringCollision(const bool isCollision);

};

