#include "stdafx.h"
#include "CppUnitTest.h"
#include"SFML/Graphics.hpp"
#include"../TowerDefenceGame/Enemy.h"
#include"../TowerDefenceGame/Globals.h"
#include"../TowerDefenceGame/Bullet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(EnemyTest)
	{
	public:

		TEST_METHOD(CheckIfEnemyIsAlive)
		{
			Enemy myEnemy;
			myEnemy.setAlive(true);
			Assert::IsTrue(myEnemy.isAlive());
		}

		TEST_METHOD(EnemyNorthMovementDirection)

		{
			Enemy myEnemy;
			myEnemy.setMovementDirection(sf::Vector2i(0, 1));
			Assert::IsTrue(myEnemy.getMovementX() == 0);
			Assert::IsTrue(myEnemy.getMovementY() == 1);
		}

		TEST_METHOD(EnemyEastMovementDirection)
		{
			Enemy myEnemy;
			myEnemy.setMovementDirection(sf::Vector2i(1, 0));
			Assert::IsTrue(myEnemy.getMovementX() == 1);
			Assert::IsTrue(myEnemy.getMovementY() == 0);
		}

		TEST_METHOD(EnemyWestMovementDirection)

		{
			Enemy myEnemy;
			myEnemy.setMovementDirection(sf::Vector2i(-1, 0));
			Assert::IsTrue(myEnemy.getMovementX() == -1);
			Assert::IsTrue(myEnemy.getMovementY() == 0);
		}

		TEST_METHOD(CollisionWithEntity)
		{
			Enemy myEnemy;
			Bullet bullet;
			bullet.setCenterPosition(sf::Vector2f(50, 50));
			bullet.setSize(sf::Vector2f(20, 20));
			myEnemy.moveTo(sf::Vector2f(50, 50));
			Assert::IsTrue(myEnemy.isCollision(bullet));
		}
		TEST_METHOD(TestCollisionWithRect)
		{
			Enemy myEnemy;
			sf::RectangleShape rectCollider;
			Assert::IsTrue(myEnemy.isCollisionWithRect(rectCollider));
		}

		TEST_METHOD(TestEnemyColor)
		{
			Enemy myEnemy;
			myEnemy.setColour(sf::Color(255, 0, 0, 255));
			Assert::IsTrue(myEnemy.getHitbox().getFillColor() == Globals::Color::enemyColor);
		}

		TEST_METHOD(EnemyHealth)
		{
			Bullet bullet;
			Enemy targetEnemy;
			int16_t targetHealth = targetEnemy.getStartingHealth();

			
			if (targetEnemy.isCollisionWithRect(bullet.getHitbox()))
			{
				targetEnemy.setIsDuringCollision(targetEnemy.isCollisionWithRect(bullet.getHitbox()));
				targetEnemy.setHealth(targetHealth--);
			}

			if (targetHealth == 0)
				targetEnemy.setAlive(false);

			Assert::IsTrue(targetEnemy.isAlive());
		}
		
		TEST_METHOD(SpeedyEnemy)
		{
			Enemy myEnemy;
			myEnemy.setColour(sf::Color::Magenta);
			Assert::IsFalse(myEnemy.getHitbox().getFillColor() == Globals::Color::speedyEnemyColor);
		}

	};

}