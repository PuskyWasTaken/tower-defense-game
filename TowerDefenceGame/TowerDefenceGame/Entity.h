#pragma once
#include "SFML/Graphics.hpp"

/* Created Entity class for game objects */

class Entity : public sf::Drawable
{
public:
	 virtual ~Entity() {};

	 Entity(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Texture& texture);
	 Entity(const sf::Vector2f& position, const sf::Vector2f& size);


	 sf::RectangleShape getHitbox() const;
	 sf::Sprite getSprite() const;
	 sf::Vector2f getPosition() const;

	 void setCenterPosition(const sf::Vector2f& newPosition);
	 void setPosition(const sf::Vector2f& newPosition);
	 void setSize(const sf::Vector2f& size);
	 void setColour(const sf::Color& newColor);

protected:

	sf::RectangleShape hitbox;
	sf::Sprite sprite;
	sf::Texture texture;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};