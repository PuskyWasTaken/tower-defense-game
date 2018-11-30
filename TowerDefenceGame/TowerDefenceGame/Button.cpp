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

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(this->hitbox);
	Entity::draw(target, states);
	target.draw(this->text);
}
