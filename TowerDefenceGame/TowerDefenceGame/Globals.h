#pragma once

namespace Globals
{
	/* Intersection Stuff*/
	const int intersectionSize = 40;
	const bool intersectionBorder = true;
	const int intersectionOutLineThickness = 2;

	namespace Color
	{
		const sf::Color towerColor = sf::Color(255, 255, 255, 50);
		const sf::Color bulletColor = sf::Color(255, 255, 255);
		const sf::Color shadowColorOn = sf::Color(210, 210, 210, 100);
		const sf::Color shadowColorOff = sf::Color(244, 66, 66, 100);
		const sf::Color drawableZoneColor = sf::Color(244, 50, 50, 60);
		const sf::Color enemyColor = sf::Color(255, 0, 0, 255);
	}
	
	const enum Cardinals {

		North,
		South,
		East,
		West
	};


	/* Enemy stuff */
	const int enemySize = 40;
	const int defaultEnemyHealth = 100;
	const float defaultEnemyMoveSpeed = 0.8f;
	const int defaultEnemySpawnRate = 5;
	const int defaultGoldRewardAmount = 5;

	namespace MovementDirections
	{
		const sf::Vector2i North(0, -1);
		const sf::Vector2i South(0, 1);
		const sf::Vector2i East(1, 0);
		const sf::Vector2i West(-1, 0);
	}

	/* Bullet Stuff */
	const float defaultBulletSpeed = 10.0;
	const sf::Vector2f defaultBulletSize(5, 5);


	/* Tower Stuff */
	const sf::Vector2f towerSize(240,240);
	const sf::Vector2f towerMainSize(40,40);
	const bool enableTowerRange = false;
	const unsigned int defaultTowerPrice = 40;
	const unsigned int speedyTowerPrice = 60;
	const unsigned int powerfullTowerPrice = 120;
	const sf::Vector2f powerfullTowerBulletSize(8, 8);
	
	const int defaultTowerDamage = 10;
	const int powerfullTowerDamage = 20;
	const float defaultTowerFireRate = 1.0f;
	const float towerSpeedyFireRate = 0.5f;

	/* Shop Stuff */
	const sf::Vector2f shopItemSize(70, 70);
	const int startingGoldAmount = 100;

	const int rasterLeft = 10;
	const int rasterTop = 80;
	const int itemSpacingHeight = 5;

	/* Shadow Stuff */

	const int32_t enemyDamage = 1;
	const int32_t startingPlayerHp = 10;
	const float frameRate = 1.0f / 60.f;
}