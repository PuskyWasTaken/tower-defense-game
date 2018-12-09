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

	sf::Text text;

public:

	sf::Font getFont() const;

	
	void setFont(const sf::Font& f);


	void setTextSize(unsigned int size);
	
	void setTextColor(sf::Color color);


	sf::Text getText() const;


	void setText(const std::string& text);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

