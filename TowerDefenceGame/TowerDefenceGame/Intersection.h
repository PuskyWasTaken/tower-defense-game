#pragma once
#include "UnmovableEntity.h"

class Intersection :
	public UnmovableEntity
{

public:

	Intersection(const sf::Vector2f& position, const sf::Vector2f& size);
	Intersection();
	~Intersection();

	bool hasEntrance(const short cardinal) const;
	void setEntrance(const short cardinal, const bool newBool);
	
	enum class cardinals
	{
		North,
		South,
		East,
		West
	};

private:

	bool entrance[4] = { false };

};

