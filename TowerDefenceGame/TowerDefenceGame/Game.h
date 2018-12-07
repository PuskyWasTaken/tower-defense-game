#pragma once
#include "IStateClass.h"
#include <SFML/Graphics.hpp>
#include <thread>

#include "Enemy.h"
#include "Intersection.h"
#include "Tower.h"
#include "Level.h"
#include "Shop.h"

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
	std::vector<std::shared_ptr<Enemy>> m_enemyArray;
	std::vector<Tower> m_towerArray;
	Shop m_shop;
	int m_gold = Globals::startingGoldAmount;

	/// Remove below
	Tower someTower;

	/* Enemy Spawn Rate */
	sf::Time m_spawnRate = sf::seconds(Globals::defaultEnemySpawnRate);
	sf::Clock m_updateClock;

public: 
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);

private:

	/* Enemy stuff */
	
	void updateEnemies();
	void updateEnemiesMovements();
	void updateEnemiesPositions();
	void updateEnemyCollision(std::shared_ptr<Enemy> enemy);
	sf::Vector2i getMovementDirection(const short entrance) const;

	/* Shop stuff */
	void handleShopPressed(const sf::Vector2f& mousePos);

	void readLevel(const std::string& level);
};

