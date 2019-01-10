#include "Shop.h"

Shop::Shop()
{
	/* Player Shop specific items */
	
	this->m_goldItem.setPosition(sf::Vector2f(this->getPosition().x + Globals::rasterLeft , this->getPosition().y + Globals::rasterTop/6));
	this->m_goldItem.setSize(sf::Vector2f(180, 40));
	this->m_goldItem.setTextPosition(m_goldItem.getPosition());

	this->m_lifePointsItem.setPosition(sf::Vector2f(this->getPosition().x + Globals::rasterLeft , this->m_goldItem.getPosition().y + m_goldItem.getHeight() + Globals::itemSpacingHeight));
	this->m_lifePointsItem.setSize(sf::Vector2f(180, 40));
	this->m_lifePointsItem.setTextPosition(m_lifePointsItem.getPosition());

	
	/* The shop's custom sale items (towers in this case) */

	/* Default Tower */
	newButton.setPosition(sf::Vector2f(this->getPosition().x ,this->getPosition().y + 1 * (Globals::shopItemSize.y / 2) + Globals::rasterTop));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(20);
	newButton.setText(" Price: " +std::to_string(Globals::defaultTowerPrice) + "\n Damage: "+ std::to_string(Globals::defaultTowerDamage) +
	"\n Fire Rate: " +std::to_string(Globals::defaultTowerFireRate));
	m_shopItems.push_back(newButton);
	
	/* Speedy Towers */
	newButton.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 4 * (Globals::shopItemSize.y / 2) + Globals::rasterTop));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(20);
	newButton.setText(" Price: " + std::to_string(Globals::speedyTowerPrice) + "\n Damage: " + std::to_string(Globals::speedyTowerDamage) +
		"\n Fire Rate: " + std::to_string(Globals::towerSpeedyFireRate));
	m_shopItems.push_back(newButton);
	
	/* Powerfull Tower */
	newButton.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 7 * (Globals::shopItemSize.y / 2) + Globals::rasterTop));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(20);
	newButton.setText(" Price: " + std::to_string(Globals::powerfullTowerPrice) + "\n Damage: " + std::to_string(Globals::powerfullTowerDamage) +
		"\n Fire Rate: " + std::to_string(Globals::powerfullTowerFireRate));
	m_shopItems.push_back(newButton);
}

Shop::~Shop()
{}

void Shop::setGold(const int newGold)
{
	this->m_goldItem.setText("Gold: " + std::to_string(newGold));
}

void Shop::setLifePoints(const int newLifePoints)
{
	this->m_lifePointsItem.setText("Life: " + std::to_string(newLifePoints));
}

void Shop::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	/* Super */
	ShopPanel::draw(target, states);
	
	target.draw(m_goldItem);
	target.draw(m_lifePointsItem);
}


