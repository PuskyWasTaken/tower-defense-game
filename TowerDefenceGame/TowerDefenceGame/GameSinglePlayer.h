#pragma once

#include "Game.h"
#include "Shop.h"

class GameSinglePlayer : public Game
{

public:
	GameSinglePlayer(const std::string &path);
	~GameSinglePlayer();

	void update(sf::RenderWindow &window) override;

private:

	Tower m_shadowEntity;
	bool m_canPlaceShadowEntity;

	/* Enemy Spawn Rate */
	bool m_gameIsWon = false;
	uint32_t m_noOfEnemiesKilled = 0;
	sf::Time m_spawnRate = sf::seconds(Globals::defaultEnemySpawnRate);
	sf::Clock m_updateClock;

private:

	/* Enemy stuff */
	void updateEnemies() override;
	void enemyWasRemoved() override;
	void enemyArrivedToEndPoint() override;

	/* Tower stuff */
	void updateShadowEntity();

	/* Game stuff */
	bool checkWinLossConditions() override;

	/* Shop stuff */
	void handleShopPressed(const sf::Vector2f& mousePos) override;
	void initShop() override;

	
};

