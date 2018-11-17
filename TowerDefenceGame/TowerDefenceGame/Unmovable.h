#pragma once
#include"IEntity.h"

class Unmovable : public IEntity
{
public:
	Unmovable();
	~Unmovable();

private:
	int positionX;
	int positionY;
	sf::RectangleShape hitbox;
	sf::VertexArray sprite; /* look after this when we'll have a sprite class */

public:
	sf::RectangleShape getHitbox();
	sf::VertexArray getSprite();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f centeredPosition);
};

