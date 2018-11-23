#include "Button.h"

Button::Button() 
	: Entity(sf::Vector2f(0,0), sf::Vector2f(50,30))
{

}

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size)
	: Entity(position, size)
{
	
}

Button::~Button()
{
}
