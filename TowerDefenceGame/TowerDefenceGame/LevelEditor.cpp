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

sf::Vector2f LevelEditor::toVector2f(const sf::Vector2i & toBeConverted)const
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
	
	//window.draw(*m_GenericIntersection);

	//Drawing the pannel
	window.draw(m_testingPanel);

	//Drawing the intersection in the pannel 

	//TODO create a drawPanel function
	for (Intersection &i : m_testingPanel.m_genericIntersections)
	{
		window.draw(i);
	}
}

void LevelEditor::handleEvent(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isMousePressed==false)
	{

		m_isMousePressed = true;
	}


	//if left mouse button is pressed get position
	if (m_isMousePressed && !m_isDrawing)
		for (Intersection &i : m_testingPanel.m_genericIntersections)
			if (i.isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
			{
				m_GenericIntersection = &i;
				m_isDrawing = true;
			}

	if (m_isDrawing && m_isMousePressed)
	{
		m_GenericIntersection->setCenterPosition(toVector2f(sf::Mouse::getPosition(window)));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isMousePressed == true)
		{

			m_isMousePressed = false;
		}
	}




}




/*{

	//if left mouse button is pressed get position
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)& (m_isMousePressed == false))
	{
		m_isMousePressed = true;
		for (Intersection &i : m_testingPanel.m_genericIntersections)
		{
			while (i.isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window)))& (sf::Mouse::isButtonPressed(sf::Mouse::Right)))
			{
					std::cout << i.getHitbox().getPosition().x << " , " << i.getHitbox().getPosition().y;
					i.setCenterPosition(toVector2f(sf::Mouse::getPosition(window)));
					draw(window);
			}

		}
	}

	//notify that the mouse is not pressed anymore and can take click
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isMousePressed == true)
	{
		m_isMousePressed = false;
	}
}
*/


