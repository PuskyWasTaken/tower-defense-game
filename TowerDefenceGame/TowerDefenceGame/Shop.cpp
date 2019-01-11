#include "Shop.h"

Shop::Shop()
{
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



