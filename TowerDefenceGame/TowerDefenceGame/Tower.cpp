#include "Tower.h"


Tower::Tower()
	: UnmovableEntity(sf::Vector2f(0,0), Globals::towerSize), m_damage(Globals::defaultTowerDamage)
{
	setFillColor();
	m_mainTower.setSize(Globals::towerMainSize);
	this->visible = Globals::enableTowerRange;
}
Tower::Tower(const sf::Vector2f& position, const sf::Vector2f& size, const float damage)
	: UnmovableEntity(position, size),	m_damage(damage)
{
	setFillColor();
	m_mainTower.setSize(Globals::towerMainSize);
	m_mainTower.setCenterPosition(this->getCenter());
	this->visible = Globals::enableTowerRange;
}
Tower::~Tower()
{
}

void Tower::setCenterPosition(const sf::Vector2f& newPosition)
{
	Entity::setCenterPosition(newPosition);
	m_mainTower.setCenterPosition(this->getCenter());
}
void Tower::setPosition(const sf::Vector2f & newPosition)
{
	Entity::setPosition(newPosition);
	m_mainTower.setPosition(this->getPosition());
}
void Tower::setFillColor()
{
	if (Globals::intersectionBorder)
	{
		this->hitbox.setOutlineThickness(Globals::intersectionOutLineThickness);
		this->hitbox.setOutlineColor(Globals::Color::towerColor);
		this->hitbox.setFillColor(sf::Color::Transparent);
	}
	else
	{
		this->hitbox.setFillColor(Globals::Color::towerColor);
	}

	this->m_mainTower.setColour(Globals::Color::shadowColorOn);

}
bool Tower::isAttacking() const
{
	return this->m_isAttacking;
}
float Tower::getDamage() const
{
	return this->m_damage;
}
bool Tower::isMainTowerVisible() const
{
	return this->m_mainTower.isVisible();
}
void Tower::fireBullet()
{
	sf::Time elapsedTime = m_updateClock.getElapsedTime();


	if (elapsedTime > m_fireRate)
	{
		/* Reset our timer */
		m_updateClock.restart();

		/* Notify that we are seeking our intruder */
		if (!m_isAttacking)
			m_isAttacking = true;

		Bullet newBullet(this->getCenter(), *m_intruder, Globals::defaultBulletSpeed);

		newBullet.setColour(Globals::Color::bulletColor);
		newBullet.setSize(Globals::defaultBulletSize);

		m_bulletArray.push_back(newBullet);
	}

}
void Tower::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	/* Super */
	Entity::draw(target,states);
	
	target.draw(m_mainTower);

	for (const Bullet& b : m_bulletArray)
		target.draw(b);

}
void Tower::setMainTowerVisible(const bool visible)
{
	m_mainTower.setVisible(visible);
}
void Tower::setFireRate(float fireRate)
{
	m_fireRate = sf::seconds(fireRate);
}
void Tower::setIntruder(std::shared_ptr<Enemy> intruder)
{
	m_intruder = intruder;
	//this->m_intruder = &intruder;
	m_isAttacking = true;
}
void Tower::update()
{
	/* Check we actually have an indruder and this wasn't called by accident */
	if (m_intruder == nullptr)
		return;

	/* If the intruder got out of range, stop shooting */
	if (!this->isCollision(*m_intruder))
	{
		m_isAttacking = false;
		return;
	}

	/* If our intruder is dded, stop shooting him */
	if (m_intruder->getHealth() <= 0)
	{
		m_isAttacking = false;
		return;
	}

	/* First, look if we have a intruder, then fire a new bullet at it */
	if (m_intruder->getHealth() > 0)
		fireBullet();

	/* Go through all of our bullets and see which ones got their target */
	for (int i = 0; i < m_bulletArray.size(); ++i)
	{
		m_bulletArray[i].update();

		if (m_bulletArray[i].isDestinationAchieved())
		{
			/* Remove the bullet from the array */
			m_bulletArray.erase(m_bulletArray.begin() + i);

			/* Substract the damage taken from the intruders health */
			m_intruder->setHealth(m_intruder->getHealth() - Globals::defaultTowerDamage);
		}
	}
}
void Tower::setMainColour(const sf::Color & newColor)
{
	this->m_mainTower.setColour(newColor);
}

sf::RectangleShape Tower::getMainHitbox() const
{
	return this->m_mainTower.getHitbox();
}



