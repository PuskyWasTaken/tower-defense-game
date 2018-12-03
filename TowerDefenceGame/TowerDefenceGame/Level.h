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
	std::vector<Entity> getDrawableZone();

	Intersection getStartingPoint();
	Intersection getEndingPoint();

private:
	
	void readThisFromFile(const std::string &file);
	
	std::vector<Intersection> m_intersectionArray;
	std::vector<Entity> m_drawableZoneArray;


	Intersection m_genericIntersection;
	Entity m_genericRectangleShape;
	Intersection m_startingPoint;
	Intersection m_endingPoint;

};

