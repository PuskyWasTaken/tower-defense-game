#include "Shop.h"



Shop::Shop()
{
	setSize(sf::Vector2f(200, 800));
	setCenterPosition(sf::Vector2f(700, 400));
	this->setColour(sf::Color::White);

	m_shopItems.push_back(Entity(sf::Vector2f(this->getPosition().x + 1 * (Globals::shopItemSize.x / 2) + Globals::rasterLeft,
											  this->getPosition().y + 1 * (Globals::shopItemSize.y / 2) + Globals::rasterTop), Globals::shopItemSize));
	m_shopItems.push_back(Entity(sf::Vector2f(this->getPosition().x + 4 * (Globals::shopItemSize.x / 2) + Globals::rasterLeft,
											  this->getPosition().y + 1 * (Globals::shopItemSize.y / 2) + Globals::rasterTop), Globals::shopItemSize));
	m_shopItems.push_back(Entity(sf::Vector2f(this->getPosition().x + 1 * (Globals::shopItemSize.x / 2) + Globals::rasterLeft,
											  this->getPosition().y + 4 * (Globals::shopItemSize.y / 2) + Globals::rasterTop), Globals::shopItemSize));
	m_shopItems.push_back(Entity(sf::Vector2f(this->getPosition().x + 4 * (Globals::shopItemSize.x / 2) + Globals::rasterLeft,
											  this->getPosition().y + 4 * (Globals::shopItemSize.y / 2) + Globals::rasterTop), Globals::shopItemSize));

}

Shop::~Shop()
{
}

void Shop::update(const sf::Vector2f & mouseCoordinates)
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

void Shop::setGold(const int newGold)
{
	this->m_goldItem.setText("Gold: " + newGold);
}

void Shop::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	Entity::draw(target, states);
	for (const Entity& shopItem : m_shopItems)
		target.draw(shopItem);
}


