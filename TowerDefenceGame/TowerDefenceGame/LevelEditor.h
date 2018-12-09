#pragma once
#include "IStateClass.h"

#include <SFML\Graphics.hpp>

#include "Intersection.h"
#include "LevelEditorPanel.h"
#include "Globals.h"
#include "MainMenu.h"
#include "Application.h"
#include "Intersection.h"
#include "../Logging/Logging.h"

#include <fstream>
#include <string>
#include <iostream>


class LevelEditor :
	public IStateClass
{
public:
	LevelEditor();
	~LevelEditor();

	//TODO implement VertexArray sprites

private:
	Intersection *m_GenericIntersection;
	Intersection m_testIntersection;

	std::vector<Intersection> m_intersectionArray;

	bool m_isRMousePressed = false;
	bool m_isLMousePressed = false;
	
	void saveToFile(const int levelId);

	sf::Vector2f toVector2f(const sf::Vector2i &toBeConverted)const;

	LevelEditorPanel m_Panel;
	std::vector<Entity> m_drawableZone;
	Entity testingRectangle;


	bool m_isDraggingGenericIntersection = false;
	bool m_isDraggingRealIntersection = false;
	bool m_isDrawing = false;
	bool m_isResizing = false;

	Intersection m_startingPoint;
	Intersection m_endingPoint;

	void setStartingPoint(const Intersection &intersection);
	void setEndingPoint(const Intersection &intersection);
	void setCorectColor();
	sf::Vector2f snapToGrid(sf::Vector2f& coordinates) const;


public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;
	void dragAndDropIntersections(sf::RenderWindow &window);
	void createDrawableZone(sf::RenderWindow &window);




};

