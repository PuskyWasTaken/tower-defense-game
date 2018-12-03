#include "Level.h"



Level::Level()
{
}

Level::Level(std::string path)
{
	readThisFromFile(path);
}


Level::~Level()
{
}

std::vector<Intersection> Level::getIntersectionArray()
{
	return m_intersectionArray;
}

std::vector<sf::RectangleShape> Level::getDrawableZone()
{
	return m_drawableZoneArray;
}

void Level::readThisFromFile(const std::string & file)
{
	std::ifstream myFile(file);
	std::string reader;
	std::string item;

	bool isPositionXRead = false;
	bool isPositionYRead = false;
	bool isSizeXRead = false;
	bool isSizeYRead = false;
	bool isExitRead = false;
	bool canReadDrawable = false;
	sf::Vector2f position;
	while (!myFile.eof())
	{
		while (myFile >> reader)
		{
			if (reader == "IntersectionEnding")
			{
				canReadDrawable = true;
			}
			std::istringstream iss(reader);

			while (std::getline(iss, item, ',') && (item != "IntersectionEnding"))
			{
				if (!canReadDrawable)
				{

					if (isPositionXRead && isPositionYRead && !isExitRead) //or if position x and y have been both read for this object
					{
						m_genericIntersection.setExit(std::stoi(item));   //std::stoi converts strings to int
						isExitRead = true;
					}

					if (isPositionXRead && !isPositionYRead && !isExitRead) //or if only position x has been read yet for this object
					{
						position.y = std::stof(item);
						isPositionYRead = true;
						m_genericIntersection.setPosition(position);
					}


					if (!isPositionXRead && !isPositionYRead && !isExitRead) // or if nothing has been read yet for this object
					{
						position.x = std::stof(item);  //std::stof converts string to float
						isPositionXRead = true;
					}


					if (isPositionXRead && isPositionYRead && isExitRead) // or if everything has been read for the intersection
					{
						isPositionXRead = false;
						isPositionYRead = false;
						isExitRead = false;
						m_intersectionArray.push_back(m_genericIntersection);
					}

				}
				else
				{
					if (isPositionXRead && isPositionYRead && isSizeXRead && !isSizeYRead) //or if position.x and position.y and size.x has been read
					{
						position.y = std::stof(item);
						isSizeYRead = true;
						m_genericRectangleShape.setSize(position);
					}

					if (isPositionXRead && isPositionYRead && !isSizeXRead && !isSizeYRead) // or if position.x and position.y has been read
					{
						position.x = std::stof(item);
						isSizeXRead = true;
					}

					if (isPositionXRead && !isPositionYRead && !isSizeXRead && !isSizeYRead) //or if only position.x has been read
					{
						position.y = std::stof(item);
						isPositionYRead = true;
						m_genericRectangleShape.setPosition(position);
					}


					if (!isPositionXRead && !isPositionYRead && !isSizeXRead && !isSizeYRead) // or if nothing has been read yet
					{
						position.x = std::stof(item);
						isPositionXRead = true;
					}


					if (isPositionXRead && isPositionYRead && isSizeXRead && isSizeYRead) //if everything has been read
					{
						isPositionXRead = false;
						isPositionYRead = false;
						isSizeXRead = false;
						isSizeYRead = false;
						m_drawableZoneArray.push_back(m_genericRectangleShape);
					}

				}

			}

		}
	}

}
