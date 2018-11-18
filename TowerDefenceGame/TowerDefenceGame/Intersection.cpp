#include "Intersection.h"


Intersection::Intersection(const sf::Vector2f& position, const sf::Vector2f& size)
	: UnmovableEntity(position, size)
{
}

Intersection::Intersection()
	: UnmovableEntity(sf::Vector2f(0,0), sf::Vector2f(40,40))
{}


Intersection::~Intersection()
{
}
