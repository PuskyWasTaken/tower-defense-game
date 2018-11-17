#pragma once
#include"IEntity.h"

class MovableEntity : public IEntity
{
public:
	MovableEntity();
	~MovableEntity();

private:
	int positionX;
	int positionY;
	sf::RectangleShape hitbox;
	sf::VertexArray sprite; /* look after this when we'll have a sprite class */
	float speed;
	sf::Vector2f movementDirection;

public:
	sf::RectangleShape getHitbox();
	sf::VertexArray getSprite();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f centeredPosition);
	void setSpeed(float speed);
	void Move();

};

