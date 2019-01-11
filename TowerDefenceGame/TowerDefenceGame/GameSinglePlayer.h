#pragma once

#include "Game.h"
#include "Shop.h"

class GameSinglePlayer : public Game
{
	#pragma message("GameSinglePlayer was included")

public:
	GameSinglePlayer(const std::string &path);
	~GameSinglePlayer();

	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow & window) override;
	void handleEvent(sf::RenderWindow &window) override;

private:

	Tower m_shadowEntity;
	bool m_canPlaceShadowEntity;

	Shop m_shop;

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
	void handleShopPressed(const sf::Vector2f& mousePos);
	void initShop();
	bool buyTower(const int price);

	
};

