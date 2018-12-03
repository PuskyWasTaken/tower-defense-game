#include "LevelEditor.h"
#include "Application.h"
#include "Intersection.h"





LevelEditor::LevelEditor()
{

}


LevelEditor::~LevelEditor()
{
}

void LevelEditor::saveToFile()
{	
	int levelId;
	std::cout << "Insert here the level id";
	std::cin >> levelId;
	std::string levelName = givePath(levelId);
	std::ofstream myFile;
	myFile.open(levelName);
	for (Intersection i : m_intersectionArray)
	{ 
		myFile << i.getPosition().x << "," << i.getPosition().y << "," << i.getExit() << "\n";
	}
	myFile<< "IntersectionEnding\n";
	for (Entity i : m_drawableZone)
	{
		myFile << i.getPosition().x << "," << i.getPosition().y << "," << i.getHitbox().getSize().x <<","<< i.getHitbox().getSize().y << "\n";
	}
	myFile << "DrawableZoneEnding\n";
	myFile << m_startingPoint.getPosition().x << "," << m_startingPoint.getPosition().y << "," << m_startingPoint.getExit() << "\n";
	myFile << "ReadStartingPointEnding\n";
	myFile << m_endingPoint.getPosition().x << "," << m_endingPoint.getPosition().y << "," << m_endingPoint.getExit() << "\n";
	std::cout << "\n Level saved with succes \n ";
}

sf::Vector2f LevelEditor::toVector2f(const sf::Vector2i & toBeConverted)const
{
	return sf::Vector2f(toBeConverted);
}

std::string LevelEditor::givePath(int & addTo)
{
	std::string path = "..\\Levels\\";
	path.append(std::to_string(addTo));
	return path;
}

void LevelEditor::setStartingPoint(const Intersection & intersection)
{
	m_startingPoint.setCenterPosition(toVector2f(intersection.getCenter()));
}

void LevelEditor::setEndingPoint(const Intersection & intersection)
{
	m_endingPoint.setCenterPosition(toVector2f(intersection.getCenter()));
}

void LevelEditor::setCorectColor()
{
	for (Intersection &i : m_intersectionArray)
	{
		if (!i.isCollisionWithRect(m_startingPoint.getHitbox()) && !i.isCollisionWithRect(m_endingPoint.getHitbox()))
		{
			if (i.getExit() == 0)
			{
				i.setColour(sf::Color::Red);
			}
			if (i.getExit() == 1)
			{
				i.setColour(sf::Color::Blue);
			}
			if (i.getExit() == 2)
			{
				i.setColour(sf::Color::Yellow);
			}
			if (i.getExit() == 3)
			{
				i.setColour(sf::Color::Green);
			}
			
		}
		
	}
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
	
	for (Entity &i : m_drawableZone)
	{
		window.draw(i);
	}
}

void LevelEditor::handleEvent(sf::RenderWindow &window)
{
	dragAndDropIntersections(window);
	createDrawableZone(window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
		saveToFile();
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
			m_testIntersection.setSize(sf::Vector2f(0,0));

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


	//delete an intersection
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < m_intersectionArray.size(); ++i)
		{
			if (m_intersectionArray[i].isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
			{
				m_intersectionArray.erase(m_intersectionArray.begin() + i);
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		for (int i = 0; i < m_intersectionArray.size(); i++)
		{
			if (m_intersectionArray[i].isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
			{
					setStartingPoint(m_intersectionArray[i]);
					m_intersectionArray[i].setColour(sf::Color::Magenta);
					setCorectColor();

			}

		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		for (int i = 0; i < m_intersectionArray.size(); i++)
		{
			if (m_intersectionArray[i].isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
			{

					setEndingPoint(m_intersectionArray[i]);
					m_intersectionArray[i].setColour(sf::Color::White);
					setCorectColor();
			}

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
		testingRectangle.getHitbox().setFillColor(sf::Color::Cyan);
		m_isLMousePressed = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		testingRectangle.setSize(toVector2f(sf::Mouse::getPosition(window)));
		m_isResizing = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
	
		for (int i = 0; i < m_drawableZone.size(); i++)
		{
			if (m_drawableZone[i].isCollisonWithPoint(toVector2f(sf::Mouse::getPosition(window))))
				m_drawableZone.erase(m_drawableZone.begin() + i);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (testingRectangle.getHitbox().getSize() != sf::Vector2f(0, 0))
		{
			m_drawableZone.push_back(testingRectangle);
		}
		testingRectangle.setSize(sf::Vector2f(0, 0));
	}

	
}
