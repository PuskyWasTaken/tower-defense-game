#pragma once
#include "IStateClass.h"
#include <SFML/Graphics.hpp>
#include <thread>

#include "Enemy.h"
#include "Intersection.h"
#include "Tower.h"
#include "Level.h"

class Game : public IStateClass
{
public:
	Game();
	~Game();

private:
	
	/* TODO: Implement threads */
	//sf::Thread
	//std::thread gameThread;

	Level m_currentLevel;
	std::vector<Enemy> m_enemyArray;
	std::vector<Tower> m_towerArray;

	/* Enemy Spawn Rate */
	sf::Time m_spawnRate = sf::seconds(Globals::defaultEnemySpawnRate);
	sf::Clock m_updateClock;

public: 
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);

private:

	void updateEnemies();
	void updateEnemiesMovements();
	void updateEnemiesPositions();
	void updateEnemyCollision(Enemy& enemy);
	sf::Vector2i getMovementDirection(const short entrance) const;

	void readLevel(const std::string& level);
};

