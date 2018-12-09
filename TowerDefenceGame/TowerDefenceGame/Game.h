#pragma once
#include "IStateClass.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <time.h>
#include <stdlib.h>

#include "Enemy.h"
#include "Intersection.h"
#include "Tower.h"
#include "Level.h"
#include "Shop.h"
#include "EndScreen.h"

class Game : public IStateClass
{
public:
	Game(const std::string &path);
	~Game();

private:
	
	/* TODO: Implement threads */
	//sf::Thread
	//std::thread gameThread;

	Level m_currentLevel;
	std::vector<std::shared_ptr<Enemy>> m_enemyArray;
	std::vector<Tower> m_towerArray;
	Shop m_shop;
	int32_t m_gold = Globals::startingGoldAmount;
	int32_t m_lifePoints = Globals::startingPlayerHp;

	Tower m_shadowEntity;
	bool m_canPlaceShadowEntity;

	/* Enemy Spawn Rate */
	bool m_gameIsWon = false;
	uint32_t m_noOfEnemiesKilled = 298;
	sf::Time m_spawnRate = sf::seconds(Globals::defaultEnemySpawnRate);
	sf::Clock m_updateClock;

public: 
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;

private:

	/* Enemy stuff */

	void updateShadowEntity();
	void updateTowers();
	void updateEnemies();
	void updateEnemiesMovements();
	void updateEnemiesPositions();
	bool checkWinLossConditions();
	bool updateEnemyCollision(std::shared_ptr<Enemy> enemy);
	sf::Vector2i getMovementDirection(const short entrance) const;

	/* Shop stuff */
	void handleShopPressed(const sf::Vector2f& mousePos);
	bool buyTower(const int price);

	void readLevel(const std::string& level);
};

