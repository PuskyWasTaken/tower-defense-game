#include "stdafx.h"
#include "CppUnitTest.h"
#include"SFML/Graphics.hpp"
#include"../TowerDefenceGame/Intersection.h"
#include"../TowerDefenceGame/Enemy.h"
#include"../TowerDefenceGame/Globals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(IntersectionTests)
	{
	public:

		TEST_METHOD(TestPannelIntersectionSize)
		{
			Intersection intersection;
			intersection.setSize(sf::Vector2f(50,50));
			Assert::IsTrue(intersection.getHitbox().getSize() == Globals::panelIntersectionSize);
		}

		TEST_METHOD(EnemyIntersectionCollision)
		{
			Intersection intersection;
			Enemy enemy;
			Assert::IsTrue(enemy.isCollisionWithRect(intersection.getHitbox()));
		}

		TEST_METHOD(CollisionWithPoint)
		{
			Intersection intersection;
			Enemy enemy;
			enemy.setCenterPosition(sf::Vector2f(60, 60));
			intersection.setCenterPosition(sf::Vector2f(60, 60));
			Assert::IsTrue(intersection.isCollisonWithPoint(enemy.getCenter()));
		}

		TEST_METHOD(SouthExit)
		{
			Intersection intersection;
			short exit=1;
			intersection.setExit(exit);
			Assert::IsTrue(intersection.getExit() == Globals::Cardinals::South);
		}

		TEST_METHOD(NorthExit)
		{
			Intersection intersection;
			short exit=0;
			intersection.setExit(exit);
			Assert::IsTrue(intersection.getExit() == Globals::Cardinals::North);
		}

		TEST_METHOD(EastExit)
		{
			Intersection intersection;
			short exit=2;
			intersection.setExit(exit);
			Assert::IsTrue(intersection.getExit() == Globals::Cardinals::East);
		}

		TEST_METHOD(WestExit)
		{
			Intersection intersection;
			short exit=3;
			intersection.setExit(exit);
			Assert::IsTrue(intersection.getExit() == Globals::Cardinals::West);
		}

	
	};
}