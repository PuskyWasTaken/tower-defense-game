#include "Game.h"

Game::Game()
{
	//Level defaultLevel();
	//m_currentLevel = &defaultLevel;
	m_currentLevel = Level("..\\Levels\\1");

	/// Remove below
	m_towerArray.push_back({ {100, 100}, {20,20}, 10 });
}

Game::~Game()
{}

void Game::update(sf::RenderWindow &window)
{
	updateEnemies();
	handleEvent(window);
}

void Game::draw(sf::RenderWindow & window)
{

	/* Draw our beautiful enemies */
	for (Enemy i : m_enemyArray)
		window.draw(i);

	/* Draw the intersections */
	for (Intersection i : m_currentLevel.intersectionArray)
		window.draw(i);

}

void Game::handleEvent(sf::RenderWindow &window)
{
}

void Game::updateEnemiesPositions()
{
	for (int i = 0; i < m_enemyArray.size(); ++i)
		m_enemyArray[i].move();
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
		newEnemy.setSpeed(1);
		m_enemyArray.push_back(newEnemy);
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
void Game::updateEnemyCollision(Enemy& enemy)
{
	/* Check for a collision */
	for (int i = 0; i < m_currentLevel.intersectionArray.size(); ++i)
	{
		/* Check if it's already collided or not */
		if (enemy.isCollision(m_currentLevel.intersectionArray[i]) && !enemy.isInCollision())
		{
			enemy.setIsDuringCollision(true);

		}
		else if (enemy.isCollision(m_currentLevel.intersectionArray[i]))
		{
			/* If the enemy is in the center of the intersection */
			if (m_currentLevel.intersectionArray[i].getICenter().x == enemy.getICenter().x
				&&  m_currentLevel.intersectionArray[i].getICenter().y == enemy.getICenter().y )
			{
				enemy.setMovementDirection(getMovementDirection(m_currentLevel.intersectionArray[i].getExit()));
				enemy.setIsDuringCollision(false);
			}
		}
	}
}

sf::Vector2i Game::getMovementDirection(const short entrance) const
{
	/* North */
	if (entrance == 0)
		return sf::Vector2i(0,-1);
	/* South */
	else if (entrance == 1)
		return sf::Vector2i(0,1);
	/* East */
	else if (entrance == 2)
		return sf::Vector2i(1,0);
	/* West */
	else if (entrance == 3)
		return sf::Vector2i(-1,0);
}

void Game::readLevel(const std::string& level)
{
	//Level newLevel(level);
	//m_currentLevel = &newLevel;
}



