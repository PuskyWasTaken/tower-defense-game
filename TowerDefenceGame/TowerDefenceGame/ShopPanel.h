#pragma once
#include "Panel.h"

class ShopPanel : public Panel
{
public:
	ShopPanel();
	~ShopPanel();

	void update(const sf::Vector2f& mouseCoordinates);
	void setGold(const int newGold);
	void setLifePoints(const int newLifePoints);

public:

	bool isSelected = false;
	int selectedItem = -1;

protected:

	std::vector<Button> m_shopItems;
	Button newButton;
	Button m_goldItem;
	Button m_lifePointsItem;


public:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

