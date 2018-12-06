#pragma once

namespace Globals
{
	/* Intersection Stuff*/
	const int intersectionSize = 40;

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
	const int defaultEnemySpawnRate = 1;

	namespace MovementDirections
	{
		const sf::Vector2i North(0, -1);
		const sf::Vector2i South(0, 1);
		const sf::Vector2i East(1, 0);
		const sf::Vector2i West(-1, 0);
	}

	/* Bullet Stuff */
	const float defaultBulletSpeed = 1.0;
	const sf::Vector2f defaultBulletSize(10, 10);


	/* Tower Stuff*/
	const int towerSize = 40;
	const int defaultTowerDamage = 10;
	const float defaultTowerFireRate = 1.0f;


	const float frameRate = 1.0f / 60.f;
}