#pragma once
#include "MultiplayerScreen.h"
#include "Application.h"
#include "GameAttacker.h"
#include "GameDefender.h"
#include "Client.h"


MultiplayerScreen::MultiplayerScreen()
{
	m_instructions.setColour(sf::Color::Transparent);
	m_instructions.setTextPosition(sf::Vector2f(Globals::windowSize.x / 4 + 45, Globals::rasterTop));
	m_instructions.setText("CHOOSE YOUR \n	 P L A Y E R \n");
	m_instructions.setTextSize(Globals::TextSize::big);

	m_defender.setSize(Globals::chosePlayerButtonSize);
	m_defender.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) - Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) - 1 * Globals::levelSelectorButtonSize.y));
	m_defender.setTextPosition(m_defender.getPosition());
	m_defender.setText("Defender");
	m_defender.setTextSize(Globals::TextSize::bigger);
	
	m_attacker.setSize(Globals::chosePlayerButtonSize);
	m_attacker.setCenterPosition(sf::Vector2f(((Globals::windowSize.x / 2) + Globals::levelSelectorButtonSize.x), (Globals::windowSize.y / 2) - 1 * Globals::levelSelectorButtonSize.y));
	m_attacker.setTextPosition(m_attacker.getPosition());
	m_attacker.setText("Attacker");
	m_attacker.setTextSize(Globals::TextSize::bigger);

	m_textBox.setPosition(sf::Vector2f(Globals::windowSize.x/2, Globals::windowSize.y/2));
	m_textBox.setText("ENTER TEXT HERE");
	
}
MultiplayerScreen::~MultiplayerScreen()
{
}

bool MultiplayerScreen::chosePlayer(const sf::Vector2f & mousePosition)
{
	Logger logger(std::cout);

	if (m_defender.isCollisonWithPoint(mousePosition))
	{
		logger.log("You've chosen to be the defender! ", Logger::Level::Info);

		if (m_selectedButton == -1)
			m_selectedButton = Client::playerTypes::Defender;

		/* Hard coded for now */
		if (Application::getInstance()->client == nullptr)
			Application::getInstance()->client = std::make_unique<Client>(Client::playerTypes::Defender, "79.116.214.20");

		return true;
	}

	if (m_attacker.isCollisonWithPoint(mousePosition))
	{
		logger.log("You've chosen to be the attacker!", Logger::Level::Info);

		/* Hard coded for now */
		if (Application::getInstance()->client == nullptr)
			Application::getInstance()->client = std::make_unique<Client>(Client::playerTypes::Attacker, "79.116.214.20");

		return true;
	}

	return false;
}
void MultiplayerScreen::update(sf::RenderWindow & window)
{
	handleEvent(window);
}
void MultiplayerScreen::draw(sf::RenderWindow & window)
{
	window.draw(m_instructions);
	window.draw(m_defender);
	window.draw(m_attacker);
	window.draw(m_textBox);
}
void MultiplayerScreen::handleEvent(sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		if (!chosePlayer((sf::Vector2f)sf::Mouse::getPosition(window)))
			updateTextBoxFocus(window);
		else
			m_textBox.setIsSelected(false);

	/* Check for the validity of our choice */
	if (!Application::getInstance()->client->getPlayerChoiceIsValid())
	{
		/* If it's invalid, that means that the player we chose is already taken so expect the server to assign us to the other player slot */
		switch (m_selectedButton)
		{
		case Client::playerTypes::Attacker:

			m_selectedButton = Client::playerTypes::Defender;
			break;

		case Client::playerTypes::Defender:

			m_selectedButton = Client::playerTypes::Attacker;
			break;

		default:

			Logger logger(std::cout);
			logger.log("You haven't chosen your player yet but somehow managed to connect to the server. This shouldn't happen!", Logger::Level::Error);
			exit((int)Logger::Level::Error);
			break;
		}

		/* Check if the game has started */
		if (Application::getInstance()->client->getHasStarted())
		{
			Logger logger(std::cout);

			switch (m_selectedButton)
			{
			case Client::playerTypes::Attacker:

				logger.log("Game Started! You are attacker", Logger::Level::Info);
				Application::getInstance()->setState(std::make_unique<GameAttacker>("..\\Levels\\1"));
				break;

			case Client::playerTypes::Defender:

				logger.log("Game Started! You are defender!", Logger::Level::Info);
				Application::getInstance()->setState(std::make_unique<GameDefender>("..\\Levels\\1"));
				break;

			default:

				
				logger.log("Game has started without both players being ready!", Logger::Level::Error);
				exit((int)Logger::Level::Error);
				break;

			}
		}

		if (m_textBox.getIsSelected())
			m_textBox.handleEvent(window);
	}
}
void MultiplayerScreen::updateTextBoxFocus(sf::RenderWindow & window) 
{
	if (m_textBox.m_button.isCollisonWithPoint((sf::Vector2f)sf::Mouse::getPosition(window)))
		m_textBox.setIsSelected(true);
	else
		m_textBox.setIsSelected(false);
}


