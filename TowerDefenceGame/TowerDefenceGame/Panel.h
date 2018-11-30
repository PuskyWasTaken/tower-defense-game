#pragma once
#include "SFML/Graphics.hpp"

#include "Entity.h"
#include "Intersection.h"

class Panel : public Entity
{
public:
	Panel();
	~Panel();
	bool mouseColidesWithEntity(const Entity& entity, const sf::Vector2f &mousePosition) const;


	bool m_isPressed = false;


	std::vector<Intersection> m_genericIntersections;


};

