#include "EnemyShop.h"



EnemyShop::EnemyShop()
{
	/* The shop's custom sale items (enemies in this case) */

	/* Default */
	newButton.setPosition(Globals::Shop::getItemPosition(this->getPosition(), 0));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(Globals::TextSize::shop);
	newButton.setText(Globals::Shop::getEnemyShopDescription(Globals::enemyType::defaultType));
	m_shopItems.push_back(newButton);

	/* Speedy */
	newButton.setPosition(Globals::Shop::getItemPosition(this->getPosition(), 1));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(Globals::TextSize::shop);
	newButton.setText(Globals::Shop::getEnemyShopDescription(Globals::enemyType::speedType));
	m_shopItems.push_back(newButton);

	/* Buff */
	newButton.setPosition(Globals::Shop::getItemPosition(this->getPosition(), 2));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(Globals::TextSize::shop);
	newButton.setText(Globals::Shop::getEnemyShopDescription(Globals::enemyType::buffType));
	m_shopItems.push_back(newButton);

	/* Tank */
	newButton.setPosition(Globals::Shop::getItemPosition(this->getPosition(), 3));
	newButton.setSize(Globals::shopItemSize);
	newButton.setTextPosition(newButton.getPosition());
	newButton.setTextSize(Globals::TextSize::shop);
	newButton.setText(Globals::Shop::getEnemyShopDescription(Globals::enemyType::tankType));
	m_shopItems.push_back(newButton);

}


EnemyShop::~EnemyShop()
{}
