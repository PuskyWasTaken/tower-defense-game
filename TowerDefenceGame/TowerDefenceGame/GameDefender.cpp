#include "GameDefender.h"

GameDefender::GameDefender(const std::string &path) : Game(path)
{
	/* Initialise our shop */
	initShop();

	/* Shadow thingy */
	m_shadowEntity.setVisible(false);
	m_shadowEntity.setMainTowerVisible(false);
}
GameDefender::~GameDefender()
{}

void GameDefender::update(sf::RenderWindow & window)
{
	/* Super */
	Game::update(window);

	updateShadowEntity();
}
void GameDefender::draw(sf::RenderWindow & window)
{
	Game::draw(window);

	/* Draw our Shop overlay */
	window.draw(m_shop);

	/* Draw the Shadow Entity */
	window.draw(m_shadowEntity);
}
void GameDefender::handleEvent(sf::RenderWindow & window)
{
	/* Super */
	Game::handleEvent(window);

	sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

	/* If right clicked pressed */
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		/* Cancel any shadow thingy */
		m_shop.isSelected = false;
		m_shadowEntity.setVisible(false);
		m_shadowEntity.setMainTowerVisible(false);

		return;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if (!m_shop.isSelected)
			m_shop.update(mousePos);
		else if (m_canPlaceShadowEntity && m_shop.isSelected && !m_shop.isCollisonWithPoint(mousePos))
		{
			/* Handle the shop button that was pressed */
			handleShopPressed(mousePos);
			m_shop.isSelected = false;
			m_shadowEntity.setVisible(false);
			m_shadowEntity.setMainTowerVisible(false);

		}

	}

	if (m_shop.isSelected && !m_shop.isCollisonWithPoint(mousePos))
	{
		/* Draw our little shadow thingy */
		if (!m_shadowEntity.isMainTowerVisible())
		{
			m_shadowEntity.setVisible(true);
			m_shadowEntity.setMainTowerVisible(true);
		}

		/* Update it's position on the mouse */
		m_shadowEntity.setCenterPosition(mousePos);
	}

	/* Cheat code to add money */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_gold += 50;
		m_shop.setGold(m_gold);
	}
}

void GameDefender::updateEnemies()
{
	/* Will have to implement multiplayer first, then enemies can be spawned */
}
void GameDefender::enemyWasRemoved()
{
	m_noOfEnemiesKilled++;

	if (m_noOfEnemiesKilled >= Globals::winConditionEnemyKillCount)
		m_gameIsWon = true;
}
void GameDefender::enemyArrivedToEndPoint()
{
	/* Substract damage from our hp */
	m_lifePoints -= Globals::enemyDamage;
	m_shop.setLifePoints(m_lifePoints);
}
void GameDefender::updateShadowEntity()
{
	/* Only update the entity if m_shop->isSelected */
	if (!m_shop.isSelected)
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
bool GameDefender::checkWinLossConditions()
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
void GameDefender::handleShopPressed(const sf::Vector2f & mousePos)
{
	if (m_shop.selectedItem < Globals::TowerTypes::noOfTowerTypes && m_shop.selectedItem > -1)
	{
		/* Buy the tower if we can */
		if (!buyTower(Globals::TowerTypes::towerObjects[m_shop.selectedItem].price))
			return;

		spawnTower(mousePos, m_shop.selectedItem);
	}
}
void GameDefender::initShop()
{
	m_gold = Globals::startingGoldAmount;
	m_lifePoints = Globals::startingPlayerHp;

	/* Set our initial gold value */
	m_shop.setGold(m_gold);

	/* Set our initial life value */
	m_shop.setLifePoints(m_lifePoints);

}
bool GameDefender::buyTower(const int price)
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

void GameDefender::spawnTower(const sf::Vector2f & mousePos, const int index)
{
	Tower newTower(mousePos, Globals::towerSize, Globals::TowerTypes::towerObjects[index].damage);
	m_towerArray.push_back(newTower);
}
