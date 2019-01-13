#include "GameAttacker.h"
#include "Shop.h"

GameAttacker::GameAttacker(const std::string &path) : Game(path)
{
	/* Initialise our shop */
	initShop();

	/* Default Spawning for the enemies */
	m_selectedSpawn = &m_currentLevel.startingPoint;

}
GameAttacker::~GameAttacker()
{}

void GameAttacker::update(sf::RenderWindow & window)
{
	/* Super */
	Game::update(window);

}
void GameAttacker::draw(sf::RenderWindow & window)
{
	Game::draw(window);

	/* Draw our Shop overlay */
	window.draw(m_shop);

}
void GameAttacker::handleEvent(sf::RenderWindow & window)
{
	/* Super */
	Game::handleEvent(window);
	sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

	sf::Event e;
	window.pollEvent(e);

	if (e.type == e.MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!m_shop.isSelected)
			m_shop.update(mousePos);
	}

	if (e.type == e.MouseButtonReleased && m_shop.isSelected)
	{
		/* Handle the shop button that was pressed */
		handleShopPressed(mousePos);
		m_shop.isSelected = false;
	}

	if (m_shop.isSelected && !m_shop.isCollisonWithPoint(mousePos))
	{
		/* Nothing for now */
	}

	/* Cheat code to add money */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_gold += 50;
		m_shop.setGold(m_gold);
	}
}

void GameAttacker::updateEnemies()
{
	/* If we received data from the attacker, handle it */
	if (Application::getInstance()->client != nullptr && Application::getInstance()->client->getRecievedFromAttacker())
	{
		int enemyType = Application::getInstance()->client->getAttackerData();

		/* Spawn the enemy and set it's starting movement direction and position, health, color */
		Enemy newEnemy(m_currentLevel.startingPoint.getCenter(), Globals::enemySize, Globals::EnemyTypes::enemyObjects[enemyType].moveSpeed, sf::Vector2i(0, 0), Globals::EnemyTypes::enemyObjects[enemyType].hp);
		newEnemy.setMovementDirection(getMovementDirection(m_currentLevel.startingPoint.getExit()));
		newEnemy.setColour(Globals::EnemyTypes::enemyObjects[enemyType].color);

		Logger logger(std::cout);
		logger.log("Spawned enemy because the other player said so.", Logger::Level::Info);

		/* Push our enemy into the array */
		m_enemyArray.push_back(std::make_shared<Enemy>(newEnemy));

		/* Tell the client we handled it */
		Application::getInstance()->client->setRecievedFromAttacker(false);
	}
	
	/* In this case the enemies are our towers */
	if (Application::getInstance()->client != nullptr && Application::getInstance()->client->getRecievedFromDefender())
	{
		/* Get the data */
		sf::Vector2f pos = { Application::getInstance()->client->getDefenderX(), Application::getInstance()->client->getDefenderY() };
		int index = { Application::getInstance()->client->getDefenderData() };

		/* Spawn the tower */
		Tower newTower(pos, Globals::towerSize, Globals::TowerTypes::towerObjects[index].damage);
		m_towerArray.push_back(newTower);

		Logger logger(std::cout);
		logger.log("Spawned tower because the other player hates you!", Logger::Level::Info);

		/* Tell the client we handled it */
		Application::getInstance()->client->setRecievedFromDefender(false);
	}
}
void GameAttacker::enemyWasRemoved()
{
	m_lifePoints -= Globals::enemyDamage;
	m_shop.setLifePoints(m_lifePoints);
}
void GameAttacker::enemyArrivedToEndPoint()
{
	/* One step closer to victory! */
	m_noOfEnemiesArrived++;

	if (m_noOfEnemiesArrived >= Globals::Multiplayer::Defender::hp)
		m_gameIsWon = true;
}

void GameAttacker::spawnEnemy(const int index)
{
/*
	Enemy newEnemy(m_selectedSpawn->getCenter(), Globals::enemySize, Globals::EnemyTypes::enemyObjects[m_shop.selectedItem].moveSpeed, sf::Vector2i(0, 0), Globals::EnemyTypes::enemyObjects[m_shop.selectedItem].hp);
	newEnemy.setMovementDirection(getMovementDirection(m_selectedSpawn->getExit()));
	newEnemy.setColour(Globals::EnemyTypes::enemyObjects[m_shop.selectedItem].color);

	m_enemyArray.push_back(std::make_shared<Enemy>(newEnemy));
*/
	/* Also tell our server that we spawned the enemy */
	if (Application::getInstance()->client != nullptr)
		Application::getInstance()->client->sendActionEnemySpawned(m_shop.selectedItem);
}
bool GameAttacker::checkWinLossConditions()
{
	/* Check with the server if the Enemy won or lost */
	if (Application::getInstance()->client != nullptr)
	{
		/* If the enemy won, that means we lose :( */
		if (Application::getInstance()->client->getEnemyWon() == Client::enemyState::EnemyWon)
		{
			/* We lost */
			m_lifePoints = 0;
		}
		/* Enemy lost, so we won :) */
		else if (Application::getInstance()->client->getEnemyWon() == Client::enemyState::EnemyLost)
		{
			/* We won */
			m_gameIsWon = true;
		}
	}

	/* Do the super later because it returns */
	return Game::checkWinLossConditions();
}
void GameAttacker::handleShopPressed(const sf::Vector2f & mousePos)
{
	if (m_shop.selectedItem < Globals::EnemyTypes::noOfEnemyTypes && m_shop.selectedItem > -1)
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::EnemyTypes::enemyObjects[m_shop.selectedItem].price))
			return;

		spawnEnemy(m_shop.selectedItem);
	}
}
void GameAttacker::initShop()
{
	m_gold = Globals::Multiplayer::Attacker::startingGoldAmmount;
	m_lifePoints = Globals::Multiplayer::Attacker::hp;

	/* Set our initial gold value */
	m_shop.setGold(m_gold);

	/* Set our initial life value */
	m_shop.setLifePoints(m_lifePoints);

}
bool GameAttacker::buyTower(const int price)
{
	/* Make sure we can afford the item */
	if (m_gold < price)
	{
		m_shop.isSelected = false;
		Logger logger(std::cout);
		logger.log("You can't afford to pay for that", Logger::Level::Warning);
		return false;
	}

	m_gold -= price;
	m_shop.setGold(m_gold);
	return true;
}
