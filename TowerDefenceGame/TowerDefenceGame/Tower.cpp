#include "Tower.h"


Tower::Tower()
	: UnmovableEntity(sf::Vector2f(0,0), sf::Vector2f(40,40)), m_damage(10)
{
}

Tower::Tower(const sf::Vector2f& position, const sf::Vector2f& size, const float damage)
	: UnmovableEntity(position, size), m_damage(damage)
{
}


Tower::~Tower()
{
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

		Bullet newBullet(this->getCenter(), *m_intruder, 1.0f);

		newBullet.setColour(sf::Color::Red);
		newBullet.setSize(sf::Vector2f(5, 5));

		m_bulletArray.push_back(newBullet);
	}

}

void Tower::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	/* Super */
	Entity::draw(target,states);
	
	for (Bullet b : m_bulletArray)
		target.draw(b);

}

void Tower::setFireRate(float fireRate)
{
	m_fireRate = sf::seconds(fireRate);
}

void Tower::setIntruder(Enemy& intruder)
{
	this->m_intruder = &intruder;
}

void Tower::update()
{
	/* First, look if we have a intruder, then fire a new bullet at it */
	if (m_intruder != nullptr && m_intruder->getHealth() > 0)
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
			m_intruder->setHealth(m_intruder->getHealth() - 10);
		}
	}
}



