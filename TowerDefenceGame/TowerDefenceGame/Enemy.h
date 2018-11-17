#pragma once
#include"MovableEntity.h" 

class Enemy : public MovableEntity
{
public:
	Enemy();
	~Enemy();

private:
	int positionX;
	int positionY;
	uint16_t health;
	bool alive;
	sf::RectangleShape anEnemy;
	float speed = 1.5f;

public:

	uint16_t getHealth() const;
	bool getAlive() const;

	void setHealth(uint16_t health);
	void setAlive(bool alive);

	sf::Vector2f getPosition() override;
	void setPosition(sf::Vector2f centeredPosition) override;

};

