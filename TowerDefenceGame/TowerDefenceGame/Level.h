#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <SFML\Graphics.hpp>
#include "Intersection.h"

class Level
{
public:
	Level();
	Level(std::string path);
	~Level();

	std::vector<Intersection> getIntersectionArray();
	std::vector<sf::RectangleShape> getDrawableZone();

private:

	void readThisFromFile(const std::string &file);
	
	std::vector<Intersection> m_intersectionArray;
	std::vector<sf::RectangleShape> m_drawableZoneArray;

	Intersection m_genericIntersection;
	sf::RectangleShape m_genericRectangleShape;

};

