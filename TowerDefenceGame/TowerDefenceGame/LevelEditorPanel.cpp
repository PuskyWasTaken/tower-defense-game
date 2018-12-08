#include "LevelEditorPanel.h"



LevelEditorPanel::LevelEditorPanel()
{
	northIntersection.setColour(sf::Color::Red);
	northIntersection.setSize(Globals::panelIntersectionSize);
	northIntersection.setPosition(sf::Vector2f(this->getPosition().x + 1 * (Globals::panelIntersectionSize.x / 2) +Globals::panelIntersectionDefaultOffset + Globals::rasterLeft,
		this->getPosition().y + 1 * (Globals::panelIntersectionSize.y / 2) + Globals::rasterLeft ));
	northIntersection.setExit(Globals::Cardinals::North);

	southIntersection.setColour(sf::Color::Blue);
	southIntersection.setSize(Globals::panelIntersectionSize);
	southIntersection.setPosition(sf::Vector2f(this->getPosition().x + 1 * (Globals::panelIntersectionSize.x / 2) + Globals::rasterTop,
		this->getPosition().y + 1 * (Globals::panelIntersectionSize.y / 2) + Globals::rasterLeft));;
	southIntersection.setExit(Globals::Cardinals::South);


	westIntersection.setColour(sf::Color::Green);
	westIntersection.setSize(Globals::panelIntersectionSize);
	westIntersection.setPosition(sf::Vector2f(this->getPosition().x + 1*(Globals::panelIntersectionSize.x/2) + Globals::rasterTop,
		this->getPosition().y + 4 * (Globals::panelIntersectionSize.y/2)+ Globals::rasterLeft ));


	westIntersection.setExit(Globals::Cardinals::West);

	eastIntersection.setColour(sf::Color::Yellow);
	eastIntersection.setSize(Globals::panelIntersectionSize);
	eastIntersection.setPosition(sf::Vector2f(this->getPosition().x + 1 * (Globals::panelIntersectionSize.x / 2) + Globals::panelIntersectionDefaultOffset + Globals::rasterLeft,
		this->getPosition().y + 4 * (Globals::panelIntersectionSize.y / 2) + Globals::rasterLeft ));
	eastIntersection.setExit(Globals::Cardinals::East);


	m_genericIntersections.push_back(northIntersection);
	m_genericIntersections.push_back(southIntersection);
	m_genericIntersections.push_back(westIntersection);
	m_genericIntersections.push_back(eastIntersection);

	northButton.setColour(sf::Color::Red);
	northButton.setSize(Globals::panelButtonSize);;
	northButton.setCenterPosition(northIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	northButton.setText("North");
	northButton.text.setPosition(northButton.getPosition());
	northButton.setTextColor(sf::Color::Black);
	

	southButton.setColour(sf::Color::Blue);
	southButton.setSize(Globals::panelButtonSize);
	southButton.setCenterPosition(southIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	southButton.setText("South");
	southButton.text.setPosition(southButton.getPosition());
	southButton.setTextColor(sf::Color::Black);

	westButton.setColour(sf::Color::Green);
	westButton.setSize(Globals::panelButtonSize);
	westButton.setCenterPosition(westIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	westButton.setText("West");
	westButton.text.setPosition(westButton.getPosition());
	westButton.setTextColor(sf::Color::Black);


	eastButton.setColour(sf::Color::Yellow);
	eastButton.setSize(Globals::panelButtonSize);
	eastButton.setCenterPosition(eastIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	eastButton.setText("East");
	eastButton.text.setPosition(eastButton.getPosition());
	eastButton.setTextColor(sf::Color::Black);

	instructions.setText("*press S to save \n zone \n * press RightClick+D  \n to create zone \n *press RightClick+F \n to resize zone\n *press ctrl+y to\n save to file\n*press Z to delete \n hovered element\n*Q-make this starting\n point\n*E-make this \nending point");
	instructions.setColour(sf::Color::White);
	instructions.setTextColor(sf::Color::Black);
	instructions.text.setPosition(sf::Vector2f(this->getCenter().x +Globals::panelDefaultTextXOffset, this->getCenter().y + Globals::panelDefaultTextYOffset));
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
