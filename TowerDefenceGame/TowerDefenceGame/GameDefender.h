#pragma once
#include "Game.h"
#include "Shop.h"

class GameDefender : public Game
{
public:
	GameDefender(const std::string &path);
	~GameDefender();

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

	void spawnTower(const sf::Vector2f& mousePos, const int index);


};

