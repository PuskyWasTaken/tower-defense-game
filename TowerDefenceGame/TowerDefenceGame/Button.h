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

public :

	sf::Text buttonText;

public:

	sf::Font getFont()
	{
		return font;
	}
	
	void setFont(sf::Font f)
	{
		this->font = font;
	}

	sf::Text getText()
	{
		return buttonText;
	}

	void setText(sf::Text text)
	{
		this->buttonText = text;
	}
};

