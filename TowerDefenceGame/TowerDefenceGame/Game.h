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
	int32_t m_gold = Globals::startingGoldAmount;
	int32_t m_lifePoints = Globals::startingPlayerHp;

	Tower m_shadowEntity;
	bool m_canPlaceShadowEntity;

	/* Enemy Spawn Rate */
	sf::Time m_spawnRate = sf::seconds(Globals::defaultEnemySpawnRate);
	sf::Clock m_updateClock;

public: 
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);

private:

	/* Enemy stuff */
	
	void updateShadowEntity();
	void updateTowers();
	void updateEnemies();
	void updateEnemiesMovements();
	void updateEnemiesPositions();
	bool updateEnemyCollision(std::shared_ptr<Enemy> enemy);
	sf::Vector2i getMovementDirection(const short entrance) const;

	/* Shop stuff */
	void handleShopPressed(const sf::Vector2f& mousePos);
	bool buyTower(const int price);

	void readLevel(const std::string& level);
};

