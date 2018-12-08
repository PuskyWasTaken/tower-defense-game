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
			myTower.setFireRate(Globals::defaultTowerFireRate);
			myTower.isAttacking();
			Assert::IsFalse(myTower.isAttacking());
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
			float damage = 17.6f;
			myTower.setDamage(damage);
			Assert::IsTrue(damage == Globals::powerfullTowerDamage);
		}

		TEST_METHOD(CheckTowerSize)
		{
			Tower myTower;
			myTower.setSize(sf::Vector2f(140, 140));
			Assert::IsFalse(myTower.getHitbox().getSize() == Globals::towerSize);
		}
	
	};
}