#include "ShopPanel.h"

ShopPanel::ShopPanel()
{}

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

void ShopPanel::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	Entity::draw(target, states);
	for (const Button& shopItem : m_shopItems)
		target.draw(shopItem);
}


