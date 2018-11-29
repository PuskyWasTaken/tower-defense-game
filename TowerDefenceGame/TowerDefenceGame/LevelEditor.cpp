#include "LevelEditor.h"
#include "Application.h"
#include "Intersection.h"

#include <iostream>



LevelEditor::LevelEditor()
{
	m_testingPanel.setSize(sf::Vector2f(200, 800));
	m_testingPanel.setCenterPosition(sf::Vector2f(700, 400));
}


LevelEditor::~LevelEditor()
{
}

sf::Vector2f LevelEditor::toVector2f(const sf::Vector2i & toBeConverted)
{
	return sf::Vector2f(toBeConverted);
}

void LevelEditor::update(sf::RenderWindow &window)
{
	handleEvent(window);
}

void LevelEditor::draw(sf::RenderWindow & window)
{
	for (Intersection i : m_intersectionArray)
	{
		window.draw(i);
	}
	window.draw(m_testingPanel);
}

void LevelEditor::handleEvent(sf::RenderWindow &window)
{

	//if left mouse button is pressed get position
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)& (m_isMousePressed == false))
	{
		m_isMousePressed = true;
		sf::Mouse::getPosition(window);
		Intersection testingIntersection(toVector2f(sf::Mouse::getPosition(window)), sf::Vector2f(60, 60)); 
		m_intersectionArray.push_back(testingIntersection);
	}

	//notify that the mouse is not pressed anymore and can take click
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isMousePressed == true)
	{
		m_isMousePressed = false;
	}
}



