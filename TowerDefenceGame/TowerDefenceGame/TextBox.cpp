#include "TextBox.h"
#include <iostream>


TextBox::TextBox()
{
	m_button.setSize(Globals::levelSelectorButtonSize);
	m_button.setColour(sf::Color::Black);
	m_button.getText().setFillColor(sf::Color::Black);
	m_button.getText().setOutlineColor(sf::Color::Black);
}


TextBox::~TextBox()
{
}

TextBox::TextBox(const sf::Vector2f & position, const sf::Vector2f & size)
{
	m_button.setCenterPosition(position);
	m_button.setSize(size);
	m_button.setTextPosition(m_button.getCenter());
}


void TextBox::update(sf::RenderWindow & window)
{
}

void TextBox::draw(sf::RenderWindow & window)
{
}

void TextBox::handleEvent(sf::RenderWindow & window)
{
	if (m_isSelected)
	{
		sf::Event e;
		window.pollEvent(e);


		if (e.type == 5)
		{
			if (e.text.unicode < 256)
			{
				m_text += (char)e.text.unicode;
				std::cout << m_text;
				m_button.setText(m_text);
			}
		}
		
	}
	
}

void TextBox::setSize(const sf::Vector2f &size)
{
	m_button.setSize(size);
}

void TextBox::setPosition(const sf::Vector2f &position)
{
	m_button.setCenterPosition(position);
	m_button.setTextPosition(m_button.getPosition());
}

Button TextBox::getButton() const
{
	return m_button;
}

void TextBox::setButton(const Button & button)
{
	m_button = button;
}

 void TextBox::setIsSelected(const bool & isSelected)
{
	m_isSelected = isSelected;
}

bool TextBox::getIsSelected() const
{
	return m_isSelected;
}

void TextBox::setText(const std::string & text)
{
	m_text = text;
}

std::string TextBox::getText()
{
	return m_text;
}

void TextBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_button);
}






