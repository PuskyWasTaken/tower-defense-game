#pragma once
#include "Game.h"

Game::Game(const std::string &path)
{
	/* Random seed */
	srand(time(nullptr));
	
	m_currentLevel = Level(path);
	Logger logger(std::cout);
	logger.log("Started game", Logger::Level::Info);
}
Game::~Game()
{}
void Game::update(sf::RenderWindow &window)
{
	/* If we reached the end, then stop everything else from working */
	if (checkWinLossConditions()) return;

	updateTowers();
	updateEnemies();
	updateEnemiesPositions();
	updateEnemiesMovements();
	handleEvent(window);

}
void Game::draw(sf::RenderWindow & window)
{
	for (const Entity& zone : m_currentLevel.drawableZoneArray)
		window.draw(zone);
	
	/* Draw our beautiful enemies */
	for (int i = 0; i < m_enemyArray.size(); ++i)
		window.draw(*m_enemyArray[i]);

	/* Draw the intersections */
	for (Intersection i : m_currentLevel.intersectionArray)
		window.draw(i);

	for (Tower i : m_towerArray)
		window.draw(i);

}
void Game::handleEvent(sf::RenderWindow &window)
{
	sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
	
	/* Exit to main menu */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Application::getInstance()->setState(std::make_unique<MainMenu>());
	}
}
void Game::updateTowers()
{
	/* Go through all of our towers and check if any enemy entered in their collision */
	for (int i = 0; i < m_towerArray.size(); ++i)
	{
		/* Go through each enemy and check if it's colliding with any */
		if (!m_towerArray[i].isAttacking())
		{
			for (int j = 0; j < m_enemyArray.size(); ++j)
				if (m_towerArray[i].isCollision(*m_enemyArray[j]))
					m_towerArray[i].setIntruder(m_enemyArray[j]);
		}
		else
		{
			m_towerArray[i].update();
		}
	}

}
void Game::updateEnemiesPositions()
{
	for (int i = 0; i < m_enemyArray.size(); ++i)
		m_enemyArray[i]->move();
}
void Game::updateEnemiesMovements()
{
	/* Go through the enemyArray and update the movement of each of them according with what intersections they collide with */
	for (int i = 0; i < m_enemyArray.size(); ++i)
	{
		/* Check if our enemy is dead */
		if (m_enemyArray[i]->getHealth() <= 0)
		{
			/* Remove the enemy from the array */
			m_enemyArray.erase(m_enemyArray.begin() + i);
			enemyWasRemoved();

			break;
		}
		
		/* Check if our is in the center of our intersection - and at the same time upate the collision */
		if (updateEnemyCollision(m_enemyArray[i]))
		{
			/* Check if it's actually the ending point */
			if (m_enemyArray[i]->isCollision(m_currentLevel.endingPoint))
			{
				/* Remove the enemy from the array */
				m_enemyArray.erase(m_enemyArray.begin() + i);
				enemyArrivedToEndPoint();
			}
		}

	}
}
bool Game::updateEnemyCollision(std::shared_ptr<Enemy> enemy)
{
	/* Check for a collision */
	for (int i = 0; i < m_currentLevel.intersectionArray.size(); ++i)
	{
		/* Check if it's already collided or not */
		if (enemy->isCollision(m_currentLevel.intersectionArray[i]) && !enemy->isInCollision())
		{
			enemy->setIsDuringCollision(true);
		}
		else if (enemy->isCollision(m_currentLevel.intersectionArray[i]))
		{
			/* If the enemy is in the center of the intersection */
			if (m_currentLevel.intersectionArray[i].getICenter().x == enemy->getICenter().x
				&&  m_currentLevel.intersectionArray[i].getICenter().y == enemy->getICenter().y )
			{
				enemy->setMovementDirection(getMovementDirection(m_currentLevel.intersectionArray[i].getExit()));
				enemy->setIsDuringCollision(false);
				return true;
			}
		}
	}

	return false;
}
bool Game::checkWinLossConditions()
{
	if (m_gameIsWon)
	{
		Application::getInstance()->setState(std::make_unique<EndScreen>(m_gameIsWon));
		return true;
	}
	else if (m_lifePoints <= 0)
	{
		Application::getInstance()->setState(std::make_unique<EndScreen>(m_gameIsWon));
		return true;
	}

	return false;
}
sf::Vector2i Game::getMovementDirection(const short entrance) const
{
	/* North */
	if (entrance == Globals::Cardinals::North)
		return Globals::MovementDirections::North;
	/* South */
	else if (entrance == Globals::Cardinals::South)
		return Globals::MovementDirections::South;
	/* East */
	else if (entrance == Globals::Cardinals::East)
		return Globals::MovementDirections::East;
	/* West */
	else if (entrance == Globals::Cardinals::West)
		return Globals::MovementDirections::West;
}
void Game::readLevel(const std::string& level)
{
	//Level newLevel(level);
	//m_currentLevel = &newLevel;
}
