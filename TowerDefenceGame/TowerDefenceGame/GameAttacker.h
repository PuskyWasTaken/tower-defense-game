#pragma once
#include "Game.h"
#include "EnemyShop.h"

class GameAttacker :
	public Game
{
public:
	GameAttacker(const std::string &path);
	~GameAttacker();

	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow & window) override;
	void handleEvent(sf::RenderWindow &window) override;

private:
	
	/* Implement Attacker Shop */
	EnemyShop m_shop;
	Intersection* m_selectedSpawn;

	uint32_t m_noOfEnemiesArrived = 0;

	sf::Clock m_updateClock;
	sf::Time m_rewardRate = sf::seconds(Globals::Multiplayer::Attacker::rewardRate);
	uint32_t m_rewardTimes = Globals::Multiplayer::Attacker::maxChainedRewardTimes;

private:

	/* Enemy stuff */
	void updateEnemies() override;
	void enemyWasRemoved() override;
	void enemyArrivedToEndPoint() override;
	void spawnEnemy(const int index);

	/* Game stuff */
	bool checkWinLossConditions() override;

	/* Shop stuff */
	void handleShopPressed(const sf::Vector2f& mousePos);
	void initShop();
	bool buyTower(const int price);
};

