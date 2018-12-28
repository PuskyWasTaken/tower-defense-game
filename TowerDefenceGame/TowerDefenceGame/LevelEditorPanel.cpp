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

	northButton.setColour(sf::Color::Transparent);
	northButton.setSize(Globals::panelButtonSize);;
	northButton.setCenterPosition(northIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	northButton.setText("  North");
	northButton.setTextSize(Globals::TextSize::small);
	northButton.setTextPosition(northButton.getPosition());

	

	southButton.setColour(sf::Color::Transparent);
	southButton.setSize(Globals::panelButtonSize);
	southButton.setCenterPosition(southIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	southButton.setText("  South");
	southButton.setTextSize(Globals::TextSize::small);
	southButton.setTextPosition(southButton.getPosition());


	westButton.setColour(sf::Color::Transparent);
	westButton.setSize(Globals::panelButtonSize);
	westButton.setCenterPosition(westIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	westButton.setText("  West");
	westButton.setTextSize(Globals::TextSize::small);
	westButton.setTextPosition(westButton.getPosition());



	eastButton.setColour(sf::Color::Transparent);
	eastButton.setSize(Globals::panelButtonSize);
	eastButton.setCenterPosition(eastIntersection.getCenter() + Globals::panelButtonDefaultOffset);
	eastButton.setText("  East");
	eastButton.setTextSize(Globals::TextSize::small);
	eastButton.setTextPosition(eastButton.getPosition());


	instructions.setColour(sf::Color::Transparent);
	instructions.setText("* press S\n to save zone\n\n* press L-Click + D\n to create zone \n\n* press L-Click + F\n to resize zone\n\n* press [1-4]\n to save to file\n\n* press Z\n to DEL hovered\n element\n\n* Q - make this\n starting point\n\n* E - make this\n ending point");
	instructions.setTextPosition(sf::Vector2f(this->getCenter().x +Globals::panelDefaultTextXOffset, this->getCenter().y + Globals::panelDefaultTextYOffset));
	instructions.setTextSize(Globals::TextSize::small);
	instructions.setSize(sf::Vector2f(0, 0));

	m_genericButtons.push_back(northButton);
	m_genericButtons.push_back(southButton);
	m_genericButtons.push_back(westButton);
	m_genericButtons.push_back(eastButton);
}


LevelEditorPanel::~LevelEditorPanel()
{
}

void LevelEditorPanel::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	Panel::draw(target, states);
	
	target.draw(this->instructions);

	target.draw(northButton);
	target.draw(southButton);
	target.draw(westButton);
	target.draw(eastButton);

	target.draw(northIntersection);
	target.draw(southIntersection);
	target.draw(westIntersection);
	target.draw(eastIntersection);
	
}
