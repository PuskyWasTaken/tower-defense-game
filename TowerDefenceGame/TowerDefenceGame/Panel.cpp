#include "Panel.h"



Panel::Panel()
{
	setSize(Globals::panelSize);
	setPosition(sf::Vector2f(Globals::windowSize.x - this->getWidth(), 0));
}


Panel::~Panel()
{
}






