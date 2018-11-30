#pragma once
#include "SFML/Graphics.hpp"

#include "Entity.h"
#include "Intersection.h"

class Panel : public Entity
{
public:
	Panel();
	~Panel();

	std::vector<Intersection> m_genericIntersections;


};

