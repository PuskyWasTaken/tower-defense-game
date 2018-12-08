#pragma once
#include "Entity.h"
#include "Button.h"

class Shop : public Entity
{

public:
	Shop();
	~Shop();

	void update(const sf::Vector2f& mouseCoordinates);
	void setGold(const int newGold);
	void setLifePoints(const int newLifePoints);

public:

	bool isSelected = false;
	int selectedItem = -1;


	enum item
	{
		towerItem,
		speedyTowerItem,
		powerfullTowerItem,
		goldUpgradeItem
	};

private:

	std::vector<Entity> m_shopItems;
	Button m_goldItem;
	Button m_lifePointsItem;


public:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

