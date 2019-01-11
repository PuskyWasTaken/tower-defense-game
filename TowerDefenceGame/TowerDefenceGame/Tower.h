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

	void setCenterPosition(const sf::Vector2f & newPosition);
	void setPosition(const sf::Vector2f& newPosition);

private: 
	
	int16_t m_damage;
	sf::Vector2f m_bulletSize = Globals::TowerTypes::towerObjects[Globals::towerType::towerItem].size;

	bool m_isAttacking = false;

	Entity m_mainTower;
	
	/* Remember to delete all bullet objects once we are done with the bulletArray */
	std::vector<Bullet> m_bulletArray;

	/* Pointer towards the intruder(enemy) */
	std::shared_ptr<Enemy> m_intruder = nullptr;
	//std::shared_ptr<Enemy> m_intruder = nullptr;

	/* Fire Rate */
	sf::Time m_fireRate = sf::seconds(Globals::TowerTypes::towerObjects[Globals::towerType::towerItem].fireRate);
	sf::Clock m_updateClock;

private:
	void fireBullet();
	void setFillColor();

protected:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:
	bool isAttacking() const;
	float getDamage() const;
	bool isMainTowerVisible() const;

	void setBulletSize(const sf::Vector2f& newSize);
	void setDamage(const int16_t newDamage);
	void setMainTowerVisible(const bool visible);
	void setFireRate(float fireRate);
	void setIntruder(std::shared_ptr<Enemy> intruder);
	void update(); 

	void setMainColour(const sf::Color& newColor);

	sf::RectangleShape getMainHitbox() const;
};

