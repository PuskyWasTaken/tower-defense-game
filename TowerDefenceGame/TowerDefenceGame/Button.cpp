#include "Button.h"
#include "..\Logging\Logging.h"
#include<fstream>

Button::Button() 
	: Entity(sf::Vector2f(0,0), sf::Vector2f(50,30))
{
	if (!font.loadFromFile("..\\Fonts\\arial.ttf"))
	{
		throw "Could not load font!";
		std::ofstream of("syso.log", std::ios::app);
		Logger logger(std::cout, Logger::Level::Error);
		logger.log("Error loading font from file", Logger::Level::Error);
	}
	text.setFont(font);
	text.setString("Default String!");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
}

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size)
	: Entity(position, size)
{
	if ( !font.loadFromFile("..\\Fonts\\arial.ttf") )
		throw "Could not load font!";

	text.setFont(font);
	text.setString("Default String!");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
}

Button::~Button()
{
}

sf::Font Button::getFont() const
{
	return font;
}

void Button::setFont(const sf::Font & f)
{
	text.setFont(f);
}

void Button::setTextSize(unsigned int size)
{
	text.setCharacterSize(size);
}

void Button::setTextColor(sf::Color color)
{
	text.setFillColor(color);
}

sf::Text Button::getText() const
{
	return text;
}

void Button::setText(const std::string & text)
{
	this->text.setString(text);
}
void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(this->hitbox);
	Entity::draw(target, states);
	target.draw(this->text);
}
