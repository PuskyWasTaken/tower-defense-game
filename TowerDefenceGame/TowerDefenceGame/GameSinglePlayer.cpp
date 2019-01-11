#include "GameSinglePlayer.h"

GameSinglePlayer::GameSinglePlayer(const std::string &path)
	: Game(path)
{
	/* Shadow thingy */
	m_shadowEntity.setVisible(false);
	m_shadowEntity.setMainTowerVisible(false);
}
GameSinglePlayer::~GameSinglePlayer()
{
}

void GameSinglePlayer::update(sf::RenderWindow & window)
{
	/* Super */
	Game::update(window);

	updateShadowEntity();
}

void GameSinglePlayer::updateEnemies()
{
	sf::Time elapsedTime = m_updateClock.getElapsedTime();

	/* Check if we should spawn 1 more enemy */
	if (elapsedTime > m_spawnRate)
	{
		/* Update our spawn rate */
		float spawnRate = Globals::defaultEnemySpawnRate - (Globals::enemySpawnCurve * m_noOfEnemiesKilled);
		if (spawnRate < Globals::minSpawnRate)
			spawnRate = 1;

		m_spawnRate = sf::seconds(spawnRate);


		/* Reset our timer */
		m_updateClock.restart();

		/* Get the type of enemy */
		bool shouldSpawn;
		int16_t enemyType;

		do
		{
			/* Get a random type of enemy */
			enemyType = rand() % Globals::EnemyTypes::noOfEnemyTypes;

			/* Should it spawn? If not, keep looking */
			shouldSpawn = rand() % 100 / Globals::EnemyTypes::enemyObjects[enemyType].chanceToSpawn + 1 == 1 ? true : false;

		} while (!shouldSpawn);

		/* Spawn the enemy and set it's starting movement direction and position, health, color */
		Enemy newEnemy(m_currentLevel.startingPoint.getCenter(), Globals::enemySize, Globals::EnemyTypes::enemyObjects[enemyType].moveSpeed, sf::Vector2i(0, 0), Globals::EnemyTypes::enemyObjects[enemyType].hp);
		newEnemy.setMovementDirection(getMovementDirection(m_currentLevel.startingPoint.getExit()));
		newEnemy.setColour(Globals::EnemyTypes::enemyObjects[enemyType].color);

		Logger logger(std::cout);
		logger.log("Spawn enemy", Logger::Level::Info);

		/* Push our enemy into the array */
		m_enemyArray.push_back(std::make_shared<Enemy>(newEnemy));
	}


}
void GameSinglePlayer::enemyWasRemoved()
{
	m_noOfEnemiesKilled++;

	if (m_noOfEnemiesKilled >= Globals::winConditionEnemyKillCount)
		m_gameIsWon = true;
}
void GameSinglePlayer::enemyArrivedToEndPoint()
{
	/* Substract damage from our hp */
	m_lifePoints -= Globals::enemyDamage;
	m_shop->setLifePoints(m_lifePoints);
}
void GameSinglePlayer::updateShadowEntity()
{
	/* Only update the entity if m_shop->isSelected */
	if (!m_shop->isSelected)
		return;

	/* Go through all of the zones and see if we collide with any */
	for (const Entity& zone : m_currentLevel.drawableZoneArray)
	{
		if (zone.isCollisionWithRect(m_shadowEntity.getMainHitbox()))
		{
			/* Have to do it this way beacause the RectangleShape doens't have == operator overloaded */
			Entity mainHitboxToEntity;
			mainHitboxToEntity.setPosition(m_shadowEntity.getMainHitbox().getPosition());
			mainHitboxToEntity.setSize(m_shadowEntity.getMainHitbox().getSize());

			sf::RectangleShape pos = zone.getCollision(mainHitboxToEntity);

			Entity collisionToEntity;
			collisionToEntity.setPosition(pos.getPosition());
			collisionToEntity.setSize(pos.getSize());

			if (mainHitboxToEntity == collisionToEntity)
			{
				/* Now check that we are not colliding with any other towers */
				for (const Tower& tower : m_towerArray)
					if (mainHitboxToEntity.isCollisionWithRect(tower.getMainHitbox()))
					{
						m_canPlaceShadowEntity = false;
						m_shadowEntity.setMainColour(Globals::Color::shadowColorOff);
						return;
					}

				m_canPlaceShadowEntity = true;
				m_shadowEntity.setMainColour(Globals::Color::shadowColorOn);
				return;
			}
		}
	}

	m_canPlaceShadowEntity = false;
	m_shadowEntity.setMainColour(Globals::Color::shadowColorOff);
}
bool GameSinglePlayer::checkWinLossConditions()
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
void GameSinglePlayer::handleShopPressed(const sf::Vector2f & mousePos)
{
	switch (m_shop->selectedItem)
	{
	case Shop::item::towerItem:
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::defaultTowerPrice))
			return;

		Tower newTower(mousePos, Globals::towerSize, Globals::defaultTowerDamage);
		m_towerArray.push_back(newTower);

		break;
	}
	case Shop::item::speedyTowerItem:
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::speedyTowerPrice))
			return;

		Tower newTower(mousePos, Globals::towerSize, Globals::defaultTowerDamage);
		newTower.setFireRate(Globals::towerSpeedyFireRate);

		m_towerArray.push_back(newTower);

		break;
	}
	case Shop::item::powerfullTowerItem:
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::powerfullTowerPrice))
			return;

		Tower newTower(mousePos, Globals::towerSize, Globals::powerfullTowerDamage);
		newTower.setBulletSize(Globals::powerfullTowerBulletSize);
		m_towerArray.push_back(newTower);

		break;
	}
	default:
		break;
	}
}
void GameSinglePlayer::initShop()
{
	m_shop = std::make_unique<Shop>();

	m_gold = Globals::startingGoldAmount;
	m_lifePoints = Globals::startingPlayerHp;

}
