#include "LevelEditor.h"
#include "Application.h"
#include "Intersection.h"

#include <iostream>



LevelEditor::LevelEditor()
{

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
	window.draw(m_Panel);
	window.draw(m_testIntersection);

	for (Intersection &i : m_intersectionArray)
	{
		window.draw(i);
	}


	//Drawing the intersection in the pannel 

	//TODO create a drawPanel function
	for (Intersection &i : m_Panel.m_genericIntersections)
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


	if (m_isMousePressed && !m_isDraggingGenericIntersection)
		for (Intersection i : m_Panel.m_genericIntersections)
			if (i.isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
			{
				m_testIntersection = i;
				m_isDraggingGenericIntersection = true;
			}

	if(m_isMousePressed && !m_isDraggingRealIntersection)
        for (Intersection &i : m_intersectionArray)
        		if (i.isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
        		{
        		m_GenericIntersection = &i;
        		m_isDraggingRealIntersection = true;
        		}
	

	if (m_isDraggingGenericIntersection && m_isMousePressed)
	{
		if (m_isDraggingGenericIntersection)
		{
			m_testIntersection.setCenterPosition(toVector2f(sf::Mouse::getPosition(window)));
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isMousePressed == true)
		{
			m_isMousePressed = false;
			m_isDraggingGenericIntersection = false;
			m_intersectionArray.push_back(m_testIntersection);
			m_testIntersection.setSize(sf::Vector2f(0,0));

		}
	}


	if (m_isDraggingRealIntersection && m_isMousePressed) {

		if (m_isDraggingRealIntersection)
		{
			m_GenericIntersection->setCenterPosition(toVector2f(sf::Mouse::getPosition(window)));
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isMousePressed == true)
		{
			m_isMousePressed = false;
			m_isDraggingRealIntersection = false;
		}
	}



}
