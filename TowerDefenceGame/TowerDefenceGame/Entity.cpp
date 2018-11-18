#include "Entity.h"


Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Texture& texture)
{}

Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size)
{
	setSize(size);
	setCenterPosition(position);
	setColour(sf::Color::Green);
}

sf::RectangleShape Entity::getHitbox() const
{
	return this->hitbox;
}

sf::Sprite Entity::getSprite() const
{
	return this->sprite;
}

sf::Vector2f Entity::getPosition() const
{
	return this->hitbox.getPosition();
}

void Entity::setCenterPosition(const sf::Vector2f& newPosition)
{
	this->hitbox.setPosition( sf::Vector2f( newPosition.x - hitbox.getSize().x / 2, newPosition.y - hitbox.getSize().y / 2 ) );
}

void Entity::setPosition(const sf::Vector2f & newPosition)
{
	this->hitbox.setPosition(newPosition);
}

void Entity::setSize(const sf::Vector2f& size)
{
	hitbox.setSize(size);
}

void Entity::setColour(const sf::Color & newColor)
{
	this->hitbox.setFillColor(newColor);
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->hitbox);
}

