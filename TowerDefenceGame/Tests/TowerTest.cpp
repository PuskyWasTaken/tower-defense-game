#include "stdafx.h"
#include "CppUnitTest.h"
#include"SFML/Graphics.hpp"
#include"../TowerDefenceGame/Tower.h"
#include"../TowerDefenceGame/Globals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TowerTests)
	{
	public:

		TEST_METHOD(CheckIfTowerIsAttacking)
		{
			Tower myTower;
			bool checkAttack = myTower.isAttacking();
			myTower.setFireRate(Globals::defaultTowerFireRate);
			checkAttack = true;
			Assert::IsTrue(checkAttack);
		}

		TEST_METHOD(CheckIfTowerIsVisible)
		{
			Tower myTower;
			myTower.setVisible(true);
			Assert::IsTrue(myTower.isVisible());
		}

		TEST_METHOD(CheckPowerfullTowerDamage)
		{
			Tower myTower;
			float damage = 20.0f;
			myTower.setDamage(damage);
			Assert::IsTrue(damage == Globals::powerfullTowerDamage);
		}

		TEST_METHOD(CheckTowerSize)
		{
			Tower myTower;
			myTower.setSize(sf::Vector2f(140, 140));
			Assert::IsFalse(myTower.getHitbox().getSize() == Globals::towerSize);
		}

		TEST_METHOD(TowerCollisionWithEntity)
		{
			Tower myTower;
			Enemy myEnemy;
			myEnemy.setCenterPosition(sf::Vector2f(20, 20));
			myTower.setCenterPosition(sf::Vector2f(20, 20));
			Assert::IsTrue(myTower.isCollision(myEnemy));
		}

		TEST_METHOD(CheckMainTowerSize)
		{
			Tower myTower;
			myTower.setSize(sf::Vector2f(40, 40));
			if (myTower.getHitbox().getSize() != Globals::towerMainSize)
				Assert::Fail();
		}

		TEST_METHOD(CheckTowerDamage)
		{
			Tower myTower;
			myTower.setDamage(10);
			if (myTower.getDamage() != Globals::defaultTowerDamage)
				Assert::Fail();
		}
	
	};
}