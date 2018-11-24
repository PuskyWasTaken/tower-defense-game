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

	sf::Font getFont() const
	{
		return font;
	}
	
	void setFont(const sf::Font& f)
	{
		text.setFont(f);
	}

	sf::Text getText() const
	{
		return text;
	}

	void setText(const std::string& text)
	{
		this->text.setString(text);
	}

protected:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

