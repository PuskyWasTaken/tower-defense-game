#pragma once
#include "IStateClass.h"
#include "Button.h"

class TextBox : public IStateClass, public sf::Drawable
{
public:
	TextBox();
	~TextBox();
	TextBox(const sf::Vector2f& position, const sf::Vector2f& size);


public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;

public:
	Button m_button;
	bool m_isSelected = true;

	std::string m_text;

	sf::Vector2f position;
	sf::Vector2f size;

	void setSize(const sf::Vector2f &size);
	void setPosition(const sf::Vector2f &position);

public:
	Button getButton() const;
	void setButton(const Button &button);

	void setIsSelected(const bool &isSelected);
	bool getIsSelected() const;

	void setText(const std::string &text);
	std::string getText();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		

};


