#pragma once
#include "Entity.h"
#include "Button.h"
#include "ShopPanel.h"

class Shop : public ShopPanel
{

public:
	Shop();
	~Shop();

	void setGold(const int newGold);
	void setLifePoints(const int newLifePoints);

public:

	enum item
	{
		towerItem,
		speedyTowerItem,
		powerfullTowerItem,
		goldUpgradeItem
	};

private:

	Button m_goldItem;
	Button m_lifePointsItem;


public:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

