#include "Tower.h"


Tower::Tower()
	: UnmovableEntity(sf::Vector2f(0,0), sf::Vector2f(Globals::towerSize, Globals::towerSize)), m_damage(Globals::defaultTowerDamage)
{
	setFillColor();

}

Tower::Tower(const sf::Vector2f& position, const sf::Vector2f& size, const float damage)
	: UnmovableEntity(position, size),	m_damage(damage)
{
	setFillColor();
}


Tower::~Tower()
{
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

}

bool Tower::isAttacking() const
{
	return this->m_isAttacking;
}

float Tower::getDamage() const
{
	return this->m_damage;
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
	
	for (const Bullet& b : m_bulletArray)
		target.draw(b);

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



