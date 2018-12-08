#include "stdafx.h"
#include "CppUnitTest.h"
#include"SFML/Graphics.hpp"
#include"../TowerDefenceGame/Entity.h"
#include"../TowerDefenceGame/Globals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(EntityTests)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			Entity entity(sf::Vector2f(10,10), sf::Vector2f(20,20));
			Assert::IsTrue(sf::Vector2f(10, 10) == entity.getPosition());
			Assert::IsTrue(sf::Vector2f(20, 20) == entity.getHitbox().getSize());

		}

	};

}