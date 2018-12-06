#pragma once
#include "UnmovableEntity.h"
#include "Bullet.h"
#include "Enemy.h"

class Tower : public UnmovableEntity
{
public:
	Tower();
	Tower(const sf::Vector2f& position, const sf::Vector2f& size, const float damage);
	~Tower();

private: 
	
	int16_t m_damage;
	bool m_isAttacking = false;

	/* Remember to delete all bullet objects once we are done with the bulletArray */
	std::vector<Bullet> m_bulletArray;

	/* Pointer towards the intruder(enemy) */
	Enemy* m_intruder = nullptr;

	/* Fire Rate */
	sf::Time m_fireRate = sf::seconds(Globals::defaultTowerFireRate);
	sf::Clock m_updateClock;

private:
	void fireBullet();

protected:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:
	bool isAttacking() const;
	float getDamage() const;

	void setFireRate(float fireRate);
	void setIntruder(Enemy& intruder);
	void update(); 
};

