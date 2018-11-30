#include "LevelEditorPanel.h"



LevelEditorPanel::LevelEditorPanel()
{
	northIntersection.setColour(sf::Color::Red);
	northIntersection.setSize(sf::Vector2f(60, 60));
	northIntersection.setCenterPosition(sf::Vector2f(650, 50));
	northIntersection.setEntrance(static_cast<short>(Intersection::cardinals::North), true);

	southIntersection.setColour(sf::Color::Blue);
	southIntersection.setSize(sf::Vector2f(60, 60));
	southIntersection.setCenterPosition(sf::Vector2f(730, 50));
	southIntersection.setEntrance(static_cast<short>(Intersection::cardinals::South), true);


	westIntersection.setColour(sf::Color::Green);
	westIntersection.setSize(sf::Vector2f(60, 60));
	westIntersection.setCenterPosition(sf::Vector2f(650, 150));
	westIntersection.setEntrance(static_cast<short>(Intersection::cardinals::West), true);

	eastIntersection.setColour(sf::Color::Yellow);
	eastIntersection.setSize(sf::Vector2f(60, 60));
	eastIntersection.setCenterPosition(sf::Vector2f(730, 150));
	eastIntersection.setEntrance(static_cast<short>(Intersection::cardinals::East), true);


	m_genericIntersections.push_back(northIntersection);
	m_genericIntersections.push_back(southIntersection);
	m_genericIntersections.push_back(westIntersection);
	m_genericIntersections.push_back(eastIntersection);
}


LevelEditorPanel::~LevelEditorPanel()
{
}
