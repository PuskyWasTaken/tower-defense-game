#include "stdafx.h"
#include "CppUnitTest.h"
#include"SFML/Graphics.hpp"
#include"../TowerDefenceGame/Bullet.h"
#include"../TowerDefenceGame/Globals.h"
#include"../TowerDefenceGame/Enemy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(BulletTests)
	{
	public:

		TEST_METHOD(CheckBulletEnemyCollision)
		{
			Bullet myBullet;
			Enemy bulletDestination;
			myBullet.setDestination(bulletDestination);
			Assert::IsTrue(bulletDestination.isCollisionWithRect(myBullet.getHitbox()));	
		}		

		TEST_METHOD(BulletValidator)
		{
			Bullet myBullet;
			myBullet.setColour(sf::Color(255, 255, 255));
			Assert::IsFalse(myBullet.getHitbox().getFillColor() != Globals::Color::bulletColor);
			
		}
	};
}