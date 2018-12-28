#include "LevelEditor.h"

LevelEditor::LevelEditor()
{}

LevelEditor::~LevelEditor()
{}

void LevelEditor::saveToFile(const int levelId)
{	
	std::string path = "..\\Levels\\" + std::to_string(levelId);

	std::ofstream myFile(path);
	if (!myFile.is_open())
	{
		Logger logger(std::cout);
		logger.log("Could not open file!", Logger::Level::Error);
		return;
	}

	for (Intersection i : m_intersectionArray)
		myFile << "I," << i.getCenter().x << "," << i.getCenter().y << "," << i.getExit() << "\n";

	for (Entity i : m_drawableZone)
		myFile << "D," << i.getCenter().x << "," << i.getCenter().y << "," << i.getHitbox().getSize().x <<","<< i.getHitbox().getSize().y << "\n";

	myFile << "S," << m_startingPoint.getCenter().x << "," << m_startingPoint.getCenter().y << "," << m_startingPoint.getExit() << "\n";
	myFile << "E," << m_endingPoint.getCenter().x << "," << m_endingPoint.getCenter().y << "," << m_endingPoint.getExit() << "\n";

	Logger logger(std::cout);
	logger.log("Saved to file Succesfully!", Logger::Level::Info);
}
sf::Vector2f LevelEditor::toVector2f(const sf::Vector2i & toBeConverted)const
{
	return sf::Vector2f(toBeConverted);
}
void LevelEditor::setStartingPoint(const Intersection & intersection)
{
	m_startingPoint = intersection;
}
void LevelEditor::setEndingPoint(const Intersection & intersection)
{
	m_endingPoint = intersection;
}
void LevelEditor::setCorectColor()
{
	for (Intersection &i : m_intersectionArray)
	{
		if (!i.isCollisionWithRect(m_startingPoint.getHitbox()) && !i.isCollisionWithRect(m_endingPoint.getHitbox()))
		{
			if (i.getExit() == Globals::Cardinals::North)
			{
				i.setColour(sf::Color::Red);
			}
			if (i.getExit() == Globals::Cardinals::South)
			{
				i.setColour(sf::Color::Blue);
			}
			if (i.getExit() == Globals::Cardinals::East)
			{
				i.setColour(sf::Color::Yellow);
			}
			if (i.getExit() == Globals::Cardinals::West)
			{
				i.setColour(sf::Color::Green);
			}
			
		}
		
	}
}
sf::Vector2f LevelEditor::snapToGrid(sf::Vector2f & coordinates) const
{
	int32_t modifiedX = coordinates.x + Globals::intersectionSize;

	/* r1 - distance from x1 to closest "square" in the left side, r2 - same but to the right side */
	int32_t r1 = modifiedX % Globals::intersectionSize;
	int32_t r2 = Globals::intersectionSize - r1;

	/* If the left side is closer than the right side */
	if (r1 < r2)
	{
		/* Snap to the left */
		coordinates.x = coordinates.x - r1;
	}
	else
	{
		/* Snap to the right */
		coordinates.x = coordinates.x + r2;
	}

	int32_t modifiedY = coordinates.y + Globals::intersectionSize;

	/* r1 - distance from x1 to closest "square" in the left side, r2 - same but to the right side */
	r1 = modifiedY % Globals::intersectionSize;
	r2 = Globals::intersectionSize - r1;

	/* If the left side is closer than the right side */
	if (r1 < r2)
	{
		/* Snap to the left */
		coordinates.y = coordinates.y - r1;
	}
	else
	{
		/* Snap to the right */
		coordinates.y = coordinates.y + r2;
	}

	return coordinates;
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
	window.draw(this->m_Panel);
	
	for (Entity &i : m_drawableZone)
	{
		window.draw(i);
	}
}
void LevelEditor::handleEvent(sf::RenderWindow &window)
{
	dragAndDropIntersections(window);
	createDrawableZone(window);

	sf::Event event;
	window.pollEvent(event);

	/* If any key was pressed */
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Num1:saveToFile(1); break;
		case sf::Keyboard::Num2 :saveToFile(2);	break;
		case sf::Keyboard::Num3 :saveToFile(3);	break;
		case sf::Keyboard::Num4 :saveToFile(4);	break;
		case sf::Keyboard::Escape:Application::getInstance()->setState(std::make_unique<MainMenu>()); break;
		default: break;
		}
	}
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
			sf::Vector2f mouseCoords = toVector2f(sf::Mouse::getPosition(window));
			m_testIntersection.setCenterPosition(mouseCoords);
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isRMousePressed == true)
		{
			sf::Vector2f gen = m_testIntersection.getCenter();
			m_testIntersection.setCenterPosition(snapToGrid(gen));
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
			sf::Vector2f mouseCoords = toVector2f(sf::Mouse::getPosition(window));
			m_GenericIntersection->setCenterPosition(mouseCoords);
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_isRMousePressed == true)
		{
			sf::Vector2f gen = m_GenericIntersection->getCenter();
			m_GenericIntersection->setCenterPosition(snapToGrid(gen));
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

	//create starting point
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

	//create ending point
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
