#pragma once
#include "Entity.h"

class Button : public Entity
{
public:
	Button();
	Button(const sf::Vector2f& position, const sf::Vector2f& size);
	~Button();

private:

	sf::Font font;
	sf::Text buttonText;
};

