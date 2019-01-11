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
		sf::Event event;
		window.pollEvent(event);
	
		/* If any key was pressed */
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Num1:
			{
				m_text += '1';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num2:
			{
				m_text += '2';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num3:
			{
				m_text += '3';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num4:
			{
				m_text += '4';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num5:
			{
				m_text += '5';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num6:
			{
				m_text += '6';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num7:
			{
				m_text += '7';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num8:
			{
				m_text += '8';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num9:
			{
				m_text += '9';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Num0:
			{
				m_text += '0';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::Period:
			{
				m_text += '.';
				m_button.setText(m_text);
				break;
			}
			case sf::Keyboard::BackSpace:
			{
				if (m_text.size() > 0)
				{
					m_text.pop_back();
					m_button.setText(m_text);
				}
				break;
			}

			default: break;
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

 void TextBox::setIsSelected(const bool isSelected)
{
	m_isSelected = isSelected;
}

bool TextBox::getIsSelected() const
{
	return m_isSelected;
}

void TextBox::setText(const std::string & text)
{
	m_button.setText(text);
}

std::string TextBox::getText()
{
	return m_text;
}

void TextBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_button);
}






