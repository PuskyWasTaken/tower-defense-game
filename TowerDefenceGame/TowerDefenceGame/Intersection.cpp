#include "Intersection.h"


Intersection::Intersection(const sf::Vector2f& position, const sf::Vector2f& size, const short exit)
	: UnmovableEntity(position, size), m_exit(exit)
{
}

Intersection::Intersection(const sf::Vector2f & position, const short exit)
	: UnmovableEntity(position, sf::Vector2f(40,40)), m_exit(exit)
{
}

Intersection::Intersection()
	: UnmovableEntity(sf::Vector2f(0,0), sf::Vector2f(40,40)), m_exit(0)
{}


Intersection::~Intersection()
{
}

short Intersection::getExit() const
{
	return this->m_exit;
}

void Intersection::setExit(const short cardinal)
{
	m_exit = cardinal;
}


