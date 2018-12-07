#include "Game.h"

Game::Game()
{
	//Level defaultLevel();
	//m_currentLevel = &defaultLevel;
	m_currentLevel = Level("..\\Levels\\1");

	/// Remove below
	someTower.setCenterPosition({500, 240});
	m_towerArray.push_back(someTower);
}

Game::~Game()
{}

void Game::update(sf::RenderWindow &window)
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


	updateEnemies();
	handleEvent(window);
}

void Game::draw(sf::RenderWindow & window)
{
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
}

void Game::updateEnemiesPositions()
{
	for (int i = 0; i < m_enemyArray.size(); ++i)
		m_enemyArray[i]->move();
}
void Game::updateEnemies()
{
	sf::Time elapsedTime = m_updateClock.getElapsedTime();

	/* Check if we should spawn 1 more enemy */
	if (elapsedTime > m_spawnRate)
	{
		/* Reset our timer */
		m_updateClock.restart();

		/* Spawn the enemy and set it's starting movement direction and position */
		Enemy newEnemy;
		newEnemy.setPosition(m_currentLevel.startingPoint.getPosition());
		newEnemy.setMovementDirection(getMovementDirection(m_currentLevel.startingPoint.getExit()));
		newEnemy.setColour(sf::Color::Blue);
		m_enemyArray.push_back(std::make_shared<Enemy>(newEnemy));
	}
	
	updateEnemiesPositions();
	updateEnemiesMovements();
}
void Game::updateEnemiesMovements()
{
	/* Go through the enemyArray and update the movement of each of them according with what intersections they collide with */
	for (int i = 0; i < m_enemyArray.size(); ++i)
		updateEnemyCollision(m_enemyArray[i]);
}
void Game::updateEnemyCollision(std::shared_ptr<Enemy> enemy)
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
			}
		}
	}
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



