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


	window.draw(testingRectangle);

	window.draw(m_Panel.instructions);

	for (Intersection &i : m_Panel.m_genericIntersections)
	{
		window.draw(i);
	}

	for (Button &i : m_Panel.m_genericButtons)
	{
		window.draw(i);
	}
	
	for (sf::RectangleShape &i : m_drawableZone)
	{
		window.draw(i);
	}
}

void LevelEditor::handleEvent(sf::RenderWindow &window)
{
	dragAndDropIntersections(window);
	createDrawableZone(window);
}



void LevelEditor::dragAndDropIntersections(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isRMousePressed==false)
	{

		m_isRMousePressed = true;
	}

	// finds the generic intersection array, those objects are treated as buttons and creates a copy (m_testIntersection)
	if(!m_isDraggingRealIntersection)
		if (m_isRMousePressed && !m_isDraggingGenericIntersection)
			for (Intersection i : m_Panel.m_genericIntersections)
				if (i.isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
				{
					m_testIntersection = i;
					m_isDraggingGenericIntersection = true;
				}

	//finds the intersection objects that are already on the canvas
	if(!m_isDraggingGenericIntersection)
		if(m_isRMousePressed && !m_isDraggingRealIntersection)
		    for (Intersection &i : m_intersectionArray)
		    		if (i.isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
		    		{
		    		m_GenericIntersection = &i;
		    		m_isDraggingRealIntersection = true;
		    		}
		


	//creates an intersection from the copy, pushes it back to the Intersection array and makes the testing Intersection invisible
	if (m_isDraggingGenericIntersection && m_isRMousePressed)
	{
		if (m_isDraggingGenericIntersection)
		{
			m_testIntersection.setCenterPosition(toVector2f(sf::Mouse::getPosition(window)));
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isRMousePressed == true)
		{
			m_isRMousePressed = false;
			m_isDraggingGenericIntersection = false;
			m_intersectionArray.push_back(m_testIntersection);
			std::cout << m_intersectionArray.size() << " ";
			m_testIntersection.setSize(sf::Vector2f(10,10));

		}
	}

	//Changes the position of the real intersection
	if (m_isDraggingRealIntersection && m_isRMousePressed) {

		if (m_isDraggingRealIntersection)
		{
			m_GenericIntersection->setCenterPosition(toVector2f(sf::Mouse::getPosition(window)));
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isRMousePressed == true)
		{
			m_isRMousePressed = false;
			m_isDraggingRealIntersection = false;
		}
	}



}

void LevelEditor::createDrawableZone(sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_isLMousePressed == false)
	{

		m_isLMousePressed = true;
	}

	if (m_isLMousePressed && !m_isDrawing && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		testingRectangle.setPosition(toVector2f(sf::Mouse::getPosition(window)));
		testingRectangle.setFillColor(sf::Color::Cyan);
		m_isLMousePressed = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		testingRectangle.setSize(toVector2f(sf::Mouse::getPosition(window)));
		m_isResizing = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (testingRectangle.getSize() != sf::Vector2f(0, 0))
		{
			m_drawableZone.push_back(testingRectangle);
		}
		testingRectangle.setSize(sf::Vector2f(0, 0));
	}

	
}
