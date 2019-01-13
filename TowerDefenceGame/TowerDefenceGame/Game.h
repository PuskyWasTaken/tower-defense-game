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
#include "EndScreen.h"
#include "ShopPanel.h"
#include "Application.h"
#include "MainMenu.h"
#include "../Logging/Logging.h"

class Game : public IStateClass
{
	#pragma message("Game is included")
public:
	Game(const std::string &path);
	virtual ~Game();

protected:
	
	/* TODO: Implement threads */
	//sf::Thread
	//std::thread gameThread;

	Level m_currentLevel;
	std::vector<std::shared_ptr<Enemy>> m_enemyArray;
	std::vector<Tower> m_towerArray;

	int32_t m_gold;
	int32_t m_lifePoints;
	bool m_gameIsWon = false;

public: 
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;

private:

	void updateEnemiesMovements();
	void updateTowers();
	void updateEnemiesPositions();
	bool updateEnemyCollision(std::shared_ptr<Enemy> enemy);

protected:

	/* Enemy stuff */
	virtual void enemyWasRemoved();
	virtual void enemyArrivedToEndPoint() = 0;
	virtual void updateEnemies() = 0;

	virtual bool checkWinLossConditions();
	sf::Vector2i getMovementDirection(const short entrance) const;

	void readLevel(const std::string& level);
};

