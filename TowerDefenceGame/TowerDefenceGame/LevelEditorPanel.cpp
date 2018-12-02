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

	northButton.setColour(sf::Color::Red);
	northButton.setSize(sf::Vector2f(80, 30));
	northButton.setCenterPosition(sf::Vector2f(650, 100));
	northButton.setText("North");
	northButton.text.setPosition(northButton.getPosition());
	northButton.setTextColor(sf::Color::Black);
	

	southButton.setColour(sf::Color::Blue);
	southButton.setSize(sf::Vector2f(80, 30));
	southButton.setCenterPosition(sf::Vector2f(730, 100));
	southButton.setText("South");
	southButton.text.setPosition(southButton.getPosition());
	southButton.setTextColor(sf::Color::Black);

	westButton.setColour(sf::Color::Green);
	westButton.setSize(sf::Vector2f(80, 30));
	westButton.setCenterPosition(sf::Vector2f(650, 200));
	westButton.setText("West");
	westButton.text.setPosition(westButton.getPosition());
	westButton.setTextColor(sf::Color::Black);


	eastButton.setColour(sf::Color::Yellow);
	eastButton.setSize(sf::Vector2f(80, 30));
	eastButton.setCenterPosition(sf::Vector2f(730, 200));
	eastButton.setText("East");
	eastButton.text.setPosition(eastButton.getPosition());
	eastButton.setTextColor(sf::Color::Black);

	instructions.setText("*press S to save \n zone \n * press LeftClick+D  \n to create zone \n *press LeftClick+F \n to resize zone");
	instructions.setColour(sf::Color::White);
	instructions.setTextColor(sf::Color::Black);
	instructions.text.setPosition(sf::Vector2f(600, 250));
	instructions.setTextSize(20);
	instructions.setSize(sf::Vector2f(0, 0));

	m_genericButtons.push_back(northButton);
	m_genericButtons.push_back(southButton);
	m_genericButtons.push_back(westButton);
	m_genericButtons.push_back(eastButton);
}


LevelEditorPanel::~LevelEditorPanel()
{
}
