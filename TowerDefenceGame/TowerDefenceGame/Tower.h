#pragma once
#include "UnmovableEntity.h"

class Tower : public UnmovableEntity
{
public:
	Tower();
	Tower(const sf::Vector2f& position, const sf::Vector2f& size, const float damage);
	~Tower();

private: 
	float damage;

public:
	float getDamage() const;
};

