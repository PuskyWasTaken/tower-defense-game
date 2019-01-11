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
	/*  */
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
	Enemy newEnemy(m_selectedSpawn->getCenter(), Globals::enemySize, Globals::EnemyTypes::enemyObjects[m_shop.selectedItem].moveSpeed, sf::Vector2i(0, 0), Globals::EnemyTypes::enemyObjects[m_shop.selectedItem].hp);
	newEnemy.setMovementDirection(getMovementDirection(m_selectedSpawn->getExit()));
	newEnemy.setColour(Globals::EnemyTypes::enemyObjects[m_shop.selectedItem].color);

	m_enemyArray.push_back(std::make_shared<Enemy>(newEnemy));
}

bool GameAttacker::checkWinLossConditions()
{
	if (m_gameIsWon)
	{
		Application::getInstance()->setState(std::make_unique<EndScreen>(m_gameIsWon));
		return true;
	}
	else if (m_lifePoints <= 0)
	{
		Application::getInstance()->setState(std::make_unique<EndScreen>(m_gameIsWon));
		return true;
	}

	return false;
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
