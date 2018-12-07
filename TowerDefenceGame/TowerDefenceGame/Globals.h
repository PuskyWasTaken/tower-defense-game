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
		const sf::Color bulletColor = sf::Color(255,255,255);
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
	const float defaultEnemyMoveSpeed = 1.0f;
	const int defaultEnemySpawnRate = 5;

	namespace MovementDirections
	{
		const sf::Vector2i North(0, -1);
		const sf::Vector2i South(0, 1);
		const sf::Vector2i East(1, 0);
		const sf::Vector2i West(-1, 0);
	}

	/* Bullet Stuff */
	const float defaultBulletSpeed = 5.0;
	const sf::Vector2f defaultBulletSize(5, 5);


	/* Tower Stuff*/
	const sf::Vector2f towerSize(240,240);
	const int defaultTowerDamage = 10;
	const float defaultTowerFireRate = 1.0f;

	/* Shop Stuff */
	const sf::Vector2f shopItemSize(70, 70);
	const int startingGoldAmount = 100;

	const int rasterLeft = 10;
	const int rasterTop = 80;

	const float frameRate = 1.0f / 60.f;
}