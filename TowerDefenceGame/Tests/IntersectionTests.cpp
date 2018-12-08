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
	
	};
}