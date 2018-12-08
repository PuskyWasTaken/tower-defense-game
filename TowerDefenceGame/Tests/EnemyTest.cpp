#include "stdafx.h"
#include "CppUnitTest.h"
#include"SFML/Graphics.hpp"
#include"../TowerDefenceGame/Entity.h"
#include"../TowerDefenceGame/MovableEntity.h"
#include"../TowerDefenceGame/Enemy.h"
#include"../TowerDefenceGame/Globals.h"

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
			Assert::IsFalse(myEnemy.isAlive() == false);
		}

		TEST_METHOD(EnemyNorthMovementDirection)

		{
			Enemy myEnemy;
			myEnemy.setMovementDirection(sf::Vector2i(1, 1));
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
			myEnemy.setMovementDirection(sf::Vector2i(-2, 0));
			Assert::IsTrue(myEnemy.getMovementX() == -1);
			Assert::IsTrue(myEnemy.getMovementY() == 0);
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
			myEnemy.setColour(sf::Color::Black);
			Assert::IsTrue(myEnemy.getHitbox().getFillColor() == Globals::Color::enemyColor);
		}
	};

}