#include "Entity.h"


Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Texture& texture, const sf::Vector2u& noOfFrames)
{
	setSize(size);
	setCenterPosition(position);
	setColour(sf::Color::Green);

	*this->texture = texture;
}

Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size)
{
	setSize(size);
	setCenterPosition(position);
	setColour(sf::Color::Green);

	this->texture = nullptr;
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

sf::Vector2i Entity::getCenter() const
{
	return sf::Vector2i(((int)getPosition().x * 2 + (int)getWidth())/2, ((int)getPosition().y * 2 + (int)getHeight())/2);
}

int32_t Entity::getWidth() const
{
	return this->hitbox.getSize().x;
}

int32_t Entity::getHeight() const
{
	return this->hitbox.getSize().y;
}

void Entity::setCenterPosition(const sf::Vector2f& newPosition)
{
	this->hitbox.setPosition( sf::Vector2f( newPosition.x - getWidth() / 2, newPosition.y - getHeight() / 2 ) );
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

bool Entity::isCollision(const Entity & otherEntity) const
{
	/* AABB Collision: true = there is a collision */
	
	if (this->getPosition().x < otherEntity.getPosition().x + otherEntity.getWidth() &&
		this->getPosition().x + this->getWidth() > otherEntity.getPosition().x &&
		this->getPosition().y < otherEntity.getPosition().y + otherEntity.getHeight() &&
		this->getPosition().y + this->getHeight() > otherEntity.getPosition().y)
	{
		return true;
	}
	return false;
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->hitbox);
}

sf::RectangleShape Entity::getCollision(const Entity & otherEntity) const
{
	/* Returns the collision area of 2 rects */
	sf::RectangleShape collision;
	collision.setSize(sf::Vector2f(0, 0));
	collision.setPosition(sf::Vector2f(0, 0));

	int32_t x1 = std::min(this->getWidth() + this->getPosition().x, otherEntity.getWidth() + otherEntity.getPosition().x);
	int32_t x2 = std::max(this->getPosition().x, otherEntity.getPosition().x);
	int32_t y1 = std::min(this->getHeight() + this->getPosition().y, otherEntity.getHeight() + otherEntity.getPosition().y);
	int32_t y2 = std::max(this->getPosition().y, otherEntity.getPosition().y);

	collision.setPosition(sf::Vector2f(std::min(x1, x2), std::min(y1, y2)));
	collision.setSize(sf::Vector2f(std::max(0, x1 - x2), std::max(0, y1 - y2)));

	return collision;
}

