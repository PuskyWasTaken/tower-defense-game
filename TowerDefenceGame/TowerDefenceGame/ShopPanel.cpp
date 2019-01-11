#include "ShopPanel.h"

ShopPanel::ShopPanel()
{
	this->m_goldItem.setPosition(sf::Vector2f(this->getPosition().x + Globals::rasterLeft, this->getPosition().y + Globals::rasterTop / 6));
	this->m_goldItem.setSize(sf::Vector2f(180, 40));
	this->m_goldItem.setTextPosition(m_goldItem.getPosition());

	this->m_lifePointsItem.setPosition(sf::Vector2f(this->getPosition().x + Globals::rasterLeft, this->m_goldItem.getPosition().y + m_goldItem.getHeight() + Globals::itemSpacingHeight));
	this->m_lifePointsItem.setSize(sf::Vector2f(180, 40));
	this->m_lifePointsItem.setTextPosition(m_lifePointsItem.getPosition());
}

ShopPanel::~ShopPanel()
{}

void ShopPanel::update(const sf::Vector2f & mouseCoordinates)
{
	/* If the mouse button was pressed and the mouse is in bounds of the Shop */
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->isCollisonWithPoint(mouseCoordinates))
	{
		/* Start checking if it pressed on any shop items */
		for (unsigned int i = 0; i < m_shopItems.size(); ++i)
		{
			/*  */
			if (m_shopItems[i].isCollisonWithPoint(mouseCoordinates))
			{
				this->isSelected = true;
				selectedItem = i;
				return;
			}
		}
	}
}

void ShopPanel::setGold(const int newGold)
{
	this->m_goldItem.setText("Gold: " + std::to_string(newGold));
}

void ShopPanel::setLifePoints(const int newLifePoints)
{
	this->m_lifePointsItem.setText("Life: " + std::to_string(newLifePoints));
}


void ShopPanel::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	Entity::draw(target, states);
	for (const Button& shopItem : m_shopItems)
		target.draw(shopItem);

	target.draw(m_goldItem);
	target.draw(m_lifePointsItem);


}


