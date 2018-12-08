#include "LevelLoader.h"


LevelLoader::LevelLoader()
{
	m_instructions.setSize(Globals::levelSelectorButtonSize);
	m_instructions.setCenterPosition(sf::Vector2f((Globals::windowSize.x / 2), (Globals::windowSize.y / 2) - 3*Globals::levelSelectorButtonSize.y));
	m_instructions.text.setCharacterSize(40);
	m_instructions.text.setPosition(m_instructions.getPosition());
	m_instructions.text.setString("Chose the level you \n want to play!");



	newButton.setSize(Globals::levelSelectorButtonSize);
	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) - Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) - 1 * Globals::levelSelectorButtonSize.y));
	newButton.text.setCharacterSize(40);
	newButton.text.setPosition(newButton.getPosition());
	newButton.text.setString(" LEVEL \n 1");
	m_levelButtonsArray.push_back(newButton);


	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) + Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) - 1 * Globals::levelSelectorButtonSize.y));
	newButton.text.setPosition(newButton.getPosition());
	newButton.text.setString(" Level \n 2");
	m_levelButtonsArray.push_back(newButton);

	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) - Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) + 1 * Globals::levelSelectorButtonSize.y));
	newButton.text.setPosition(newButton.getPosition());
	newButton.text.setString(" Level \n 3");
	m_levelButtonsArray.push_back(newButton);

	newButton.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) + Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) + 1 * Globals::levelSelectorButtonSize.y));
	newButton.text.setPosition(newButton.getPosition());
	newButton.text.setString(" Level \n 4");
	m_levelButtonsArray.push_back(newButton);







}


LevelLoader::~LevelLoader()
{
}

void LevelLoader::choseLevel(const sf::Vector2f & mousePosition)
{
	for (int i = 0; i < m_levelButtonsArray.size(); i++)
	{
		if (m_levelButtonsArray[i].isCollisonWithPoint(mousePosition))
		{
			Application::getInstance()->setState(std::make_unique<Game>("..\\Levels\\" + std::to_string(i + 1)));
		}
	}
}

void LevelLoader::update(sf::RenderWindow & window)
{
	handleEvent(window);
}

void LevelLoader::draw(sf::RenderWindow & window)
{
	window.draw(m_instructions);
	for (Button &button : m_levelButtonsArray)
	{
		window.draw(button);
	}
}

void LevelLoader::handleEvent(sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		choseLevel((sf::Vector2f)sf::Mouse::getPosition(window));
}
