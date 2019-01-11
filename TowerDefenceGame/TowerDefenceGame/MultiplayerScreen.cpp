#include "MultiplayerScreen.h"



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
	
}


MultiplayerScreen::~MultiplayerScreen()
{
}

void MultiplayerScreen::chosePlayer(const sf::Vector2f & mousePosition)
{
	Logger logger(std::cout);

	if (m_defender.isCollisonWithPoint(mousePosition))
	{
		logger.log("You've chosen to be the defender! ", Logger::Level::Info);
	}

	if (m_attacker.isCollisonWithPoint(mousePosition))
	{
		logger.log("You've chosen to be the attacker!", Logger::Level::Info);
	}
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
}

void MultiplayerScreen::handleEvent(sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		chosePlayer((sf::Vector2f)sf::Mouse::getPosition(window));
}