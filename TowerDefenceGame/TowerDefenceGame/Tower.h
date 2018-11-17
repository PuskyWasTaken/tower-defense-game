#pragma once
#include"Unmovable.h"

class Tower : Unmovable
{
public:
	Tower();
	~Tower();

private:
	int positionX;
	int positionY;
	sf::RectangleShape hitbox;
	sf::VertexArray sprite; 
	float damage;
public:
	sf::RectangleShape getHitbox() override;
	sf::VertexArray getSprite()override;
	sf::Vector2f getPosition() override;
	void setPosition(sf::Vector2f centeredPosition) override;

	float getDamage();
};

