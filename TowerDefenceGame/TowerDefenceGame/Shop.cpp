#include "Shop.h"

Shop::Shop()
{
	/* The shop's custom sale items (towers in this case) */

	/* Default Tower */
	newButton.setPosition(Globals::Shop::getItemPosition(this->getPosition(), 0));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(Globals::TextSize::shop);
	newButton.setText(Globals::Shop::getShopDescription(Globals::towerType::towerItem));
	m_shopItems.push_back(newButton);
	
	/* Speedy Towers */
	newButton.setPosition(Globals::Shop::getItemPosition(this->getPosition(), 1));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(Globals::TextSize::shop);
	newButton.setText(Globals::Shop::getShopDescription(Globals::towerType::speedyTowerItem));
	m_shopItems.push_back(newButton);
	
	/* Powerfull Tower */
	newButton.setPosition(Globals::Shop::getItemPosition(this->getPosition(), 2));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(Globals::TextSize::shop);
	newButton.setText(Globals::Shop::getShopDescription(Globals::towerType::powerfullTowerItem));
	m_shopItems.push_back(newButton);
}

Shop::~Shop()
{}



