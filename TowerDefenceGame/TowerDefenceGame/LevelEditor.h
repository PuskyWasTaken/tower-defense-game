#pragma once
#include "IStateClass.h"

#include <SFML\Graphics.hpp>

#include "Intersection.h"
#include "Panel.h"


class LevelEditor :
	public IStateClass
{
public:
	LevelEditor();
	~LevelEditor();

	//TODO implement VertexArray sprites

private:
	sf::VertexArray sprites();  //TODO: to look after when sprite class is done
	sf::RenderTexture tiles();  //Tiles-> to pe converted in pgn
	Intersection m_GenericIntersection;

	std::vector<Intersection> m_intersectionArray;
	bool m_isMousePressed = false;
	sf::Vector2f toVector2f(const sf::Vector2i &toBeConverted);
	Panel m_testingPanel;


public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;


};

