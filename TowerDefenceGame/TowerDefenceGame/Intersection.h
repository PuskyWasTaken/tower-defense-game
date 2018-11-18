#pragma once
#include "UnmovableEntity.h"

class Intersection :
	public UnmovableEntity
{

public:

	Intersection(const sf::Vector2f& position, const sf::Vector2f& size);
	Intersection();
	~Intersection();

private:


};

