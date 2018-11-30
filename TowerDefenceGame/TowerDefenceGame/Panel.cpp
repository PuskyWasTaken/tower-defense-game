#include "Panel.h"



Panel::Panel()
{
	Intersection someIntersection;
	someIntersection.setColour(sf::Color::Red);
	someIntersection.setSize(sf::Vector2f(60, 60));
	someIntersection.setCenterPosition(sf::Vector2f(60, 60));
	someIntersection.setEntrance(static_cast<short>(Intersection::cardinals::North), true);

	m_genericIntersections.push_back(someIntersection);
}


Panel::~Panel()
{
}






