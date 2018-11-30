#pragma once
#include "IStateClass.h"

#include <SFML\Graphics.hpp>

#include "Intersection.h"
#include "LevelEditorPanel.h"


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
	bool m_isMousePressed = false;
	sf::Vector2f toVector2f(const sf::Vector2i &toBeConverted)const;
	LevelEditorPanel m_Panel;


public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;


	bool m_isDraggingGenericIntersection = false;
	bool m_isDraggingRealIntersection = false;


};

